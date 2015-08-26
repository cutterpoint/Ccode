/****************************************************************************
时间：2015年8月24日17:13:47
作者：cutter_point

文件：BiThr.cpp

功能：实现我们的线索二叉树

****************************************************************************/

#include "stdafx.h"
#include "BiThr.h"

#include <iostream>

BiThr::BiThr()
{
}


BiThr::~BiThr()
{
	delete this->Thrt;
}

/**
*我们的二叉树构建函数
*@param  int *startPreorder  前序遍历的第一个节点的指针
*@param  int *endPreorder  前序遍历的最后一个节点的指针
*@param  int *startInorder  中序遍历的第一个节点的指针
*@param  int *endInorder  中序遍历的最后一个节点的指针
*@return BinaryTreeNode* 返回我们的根节点
*/
BiThrNode* BiThr::constructCore(char *startPreorder, char *endPreorder, char *startInorder, char *endInorder)
{
	char value = *startPreorder;
	//我们首先为当前的节点创建一个对象
	BiThrNode *btn = new BiThrNode();
	btn->data = value;
	btn->lchild = btn->rchild = nullptr;
	btn->LTag = btn->RTag = BiThrNode::PointerTag::Thread;

	//接下来是我们的递归终止条件
	if (startPreorder == endPreorder)
	{
		if (startInorder == endInorder && *startPreorder == *startInorder)
		{
			//OK，这个已经是叶子节点了
			return btn;
		}
		else
		{
			throw std::exception("前序数列与中序数列不匹配");
		}
	}//if

	char *rootInorder = startInorder;
	//在中序中找到当前根,也就是btn
	while (rootInorder <= endInorder && *rootInorder != value)
	{
		++rootInorder;
	}//while

	//我们看看是找到了，还是到了末尾
	if (rootInorder > endInorder && *rootInorder != value)
	{
		throw std::exception("数据不匹配，不能形成唯一二叉树");
	}//if

	//递归
	int leftlength = rootInorder - startInorder;	//我们中序遍历的左半边
	if (leftlength > 0)
	{
		btn->LTag = BiThrNode::PointerTag::Link;
		btn->lchild = this->constructCore(startPreorder + 1, startPreorder + leftlength, startInorder, rootInorder - 1);
	}
	//右边,右边如果还有元素的话
	if ((endInorder - rootInorder) > 0)
	{
		btn->RTag = BiThrNode::PointerTag::Link;
		btn->rchild = constructCore(startPreorder + leftlength + 1, endPreorder, rootInorder + 1, endInorder);
	}

	//返回根
	return btn;
}

/**
* 创建线索二叉树，根据前序
*/
void BiThr::createBiThr(char *preOrder, char *inOrder, int length)
{
	if (preOrder == nullptr || inOrder == nullptr || length <= 0)
	{
		this->Thrt = nullptr;
	}//if

	//我们把节点返回
	this->Thrt = constructCore(preOrder, preOrder + length - 1, inOrder, inOrder + length - 1);
}

/**
* 我们建立一个函数，用来访问一个节点的内容
*/
void BiThr::visit(BiThrNode *p)
{
	std::cout << "左Tag-数据-右Tag" << std::endl << p->LTag << "-" << p->data << "-" << p->RTag << std::endl;
}

/**
* 对二叉树进行线索化时使用到的，中序遍历二叉树
*/
void BiThr::inThreading(BiThrNode *treeNode)
{
	//我们递归对这个二叉树进行中序遍历
	if (treeNode != nullptr)
	{
		//中序遍历，优先遍历左子树
		inThreading(treeNode->lchild);
		if (treeNode == nullptr)
		{
			//如果上面的递归结束，到了叶子节点，或者左边已经是空节点了，那么我们就把他进行线索化，指向前驱
			treeNode->lchild = pre;
			treeNode->LTag = BiThrNode::PointerTag::Thread;
		}//if
		//在设定新的前驱之前，我们前面一个前驱的后继就是当前的节点
		if (pre->rchild == nullptr)
		{
			pre->rchild = treeNode;
			pre->LTag = BiThrNode::PointerTag::Thread;
		}//if
		//左边结束，中间
		pre = treeNode;

		//最后右边
		inThreading(treeNode->rchild);
	}//if
}

/**
*  把线索二叉树进行线索化
*/
void BiThr::inOrderThreading()
{
	//我们先创建一个空的头结点，左边用来指向我们的二叉树的根，右边指向最后一个元素
	BiThrNode *pHead = new BiThrNode();
	pHead->LTag = BiThrNode::PointerTag::Link;
	pHead->rchild = pHead;	//先暂时把右边指向自己因为我们不知道，二叉树是否存在
	pHead->RTag = BiThrNode::PointerTag::Thread;
	//接下来判断二叉树是否存在
	if (Thrt == nullptr)
	{
		//如果二叉树不存在
		pHead->lchild = pHead;	//全都指向自己
	}//if
	else
	{
		pre = pHead;	//最开始的前驱，就是空的头节点
		pHead->lchild = Thrt;	//左边指向根
		inThreading(Thrt);	//把二叉树进行线索化
		//最后我们的前序(pre)在线索化之后，指向的是遍历到的中序的最后一个节点
		pre->rchild = pHead;
		pre->RTag = BiThrNode::PointerTag::Thread;
		//最后我们的头结点的右边指向最后一个二叉树的节点
		pHead->rchild = pre;
	}//else

	//最后得到新的头结点
	Thrt = pHead;
}

/**
* 对线索二叉树进行遍历
*/
void BiThr::inOrderTraverse_Thr()
{
	BiThrNode *p = Thrt->lchild;	//根节点
	while (p != Thrt)
	{
		while (p->LTag == BiThrNode::PointerTag::Link)
		{
			p = p->lchild;
		}//while
		visit(p);	//访问当前节点
		while (p->RTag == BiThrNode::PointerTag::Thread && p->rchild != Thrt)
		{
			//我们把后继的线索全部遍历了，之后我们在回到我们的二叉树
			p = p->rchild;
			visit(p);
		}//while
		p = p->rchild;
	}//while
}


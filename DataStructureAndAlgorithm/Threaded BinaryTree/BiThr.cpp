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
		btn->lchild = this->constructCore(startPreorder + 1, startPreorder + leftlength, startInorder, rootInorder - 1);
		btn->LTag = BiThrNode::PointerTag::Link;
	}
	//右边,右边如果还有元素的话
	if ((endInorder - rootInorder) > 0)
	{
		btn->rchild = constructCore(startPreorder + leftlength + 1, endPreorder, rootInorder + 1, endInorder);
		btn->LTag = BiThrNode::PointerTag::Link;
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
	std::cout << "左Tag-数据-右Tag" << std::endl << p->LTag << "-" << p->data << "-" << p->RTag << endl;
}

/**
* 对线索二叉树进行遍历
* 函数指针
*/
void inOrderTraverse_Thr(void* (*f)(BiThrNode* p))
{

}


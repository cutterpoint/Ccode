/****************************************************************************
时间：2015年10月3日19:29:38
作者：cutter_point

文件：BinarySortTree.h

功能：实现我们的查找的二叉排序树

****************************************************************************/
#include "BinarySortTree.h"


BinarySortTree::BinarySortTree()
{
}


BinarySortTree::~BinarySortTree()
{
	delete root;
}

/**
 *  删除二叉排序树中的节点
 */
bool BinarySortTree::deleteBST(BinaryTreeNode *p, int elem)
{
	//如果这个二叉树存在这个elem，那么我们删除他
	//首先判断树是否纯在
	if (p == nullptr)
	{
		return false;
	}//if
	else
	{
		//我们遍历这个数
		if (p->data == elem)
		{
			return delNode(p);
		}//if
		else if (p->data < elem)
		{
			//如果比我们要找的值小,说明值在右边
			return deleteBST(p->rchild, elem);
		}//else if
		else
		{
			return deleteBST(p->lchild, elem);
		}//else
	}//else if
}

/**
 * 在树中删除这个节点
 */
bool BinarySortTree::delNode(BinaryTreeNode *p)
{
	BinaryTreeNode *q;
	if (p->lchild == nullptr)
	{
		//如果右子树为空的话,那么我们删除这个节点的时候
		//只要把右子树代替原来的节点就可以了
		q = p; p = p->rchild;
		delete q;	//回收
	}//if
	else if (p->rchild == nullptr)
	{
		q = p; p = p->lchild;
		delete q;
	}//else if
	else
	{
		//如果左右都不空
		q = p; BinaryTreeNode *s = p->lchild;	//s是我们等会用来和p交换的节点
		//首先确保s的右边为空，应为我们和交换的目标是目标节点左边下面的最大的那个数，也就是目标节点额直接前驱
		while (s->rchild != nullptr)
		{
			q = s;
			s = s->rchild;
		}//while
		//交换s和p
		p->data = s->data;
		//判断q我们交换节点的前面素双亲节点是不是就是我们要删除的节点
		if (q != p)
		{
			//如果不是，就把前驱节点的双亲节点的右子树设定为，我们前驱的左子树
			q->rchild = s->lchild;
		}//if
		else
		{
			//如果是，那么把我们前驱节点的左子树直接给交换之后的节点的左孩子
			q->lchild = s->lchild;
		}//else
	}//else

	return true;
}

/**
 * 在二叉树中查找相应的元素
 * 这里f的初始值为nullptr
 * 注意在为中间的参数设定缺省的初值的时候，后面的都要设定
 * t是我们的查找树的根
 * p指向该元素节点（查找成功），或者指向p指向查找的路径上最后一个节点（查找失败）
 * f指向T的双亲，为了后面递归的方便
 */
bool BinarySortTree::searchBST(int key, BinaryTreeNode *t, BinaryTreeNode *f = nullptr, BinaryTreeNode *p = nullptr)
{
	if (this->root == nullptr)
	{
		//如果根为空的话
		p = f;	//p指向t的双亲
		return false;
	}//if
	else if (key == t->data)
	{
		//如果相等，那么就是找到了
		p = t;
		return true;
	}//else if
	else if (key < t->data)
	{
		//比我们要找的值小
		return this->searchBST(key, t->lchild, t, p);
	}//else if
	else
	{
		//比值大
		return searchBST(key, t->rchild, t, p);
	}//else

}

/**
 * 二叉排序的插入算法
 */
bool BinarySortTree::insertBST(int elem)
{
	BinaryTreeNode *p = nullptr;
	BinaryTreeNode *t = root;
	//在插入之前我们要确定，树中没有这个元素，以免重复插入
	if (!searchBST(elem, t, nullptr, p))
	{
		//如果树中没有这个元素，我们就插入
		BinaryTreeNode *s = new BinaryTreeNode();
		s->data = elem;
		//由于p是路径上最后一个元素
		if (p != nullptr)
		{
			//p为空，说明这个树就没有元素,那么我们就把这个元素作为根元素
			root = s;
		}//if
		else if (elem < p->data)
		{
			//这个元素比最后一个元素小
			p->lchild = s;
		}//else if
		else
		{
			p->rchild = s;
		}//else

		return true;
	}
	else
		return false;
}
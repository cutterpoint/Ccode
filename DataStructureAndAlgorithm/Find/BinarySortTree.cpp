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
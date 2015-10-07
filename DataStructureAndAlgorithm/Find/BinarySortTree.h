/****************************************************************************
时间：2015年10月3日19:29:38
作者：cutter_point

文件：BinarySortTree.h

功能：实现我们的查找的二叉排序树

****************************************************************************/

#ifndef _BINARY_SORT_TREE_H_
#define _BINARY_SORT_TREE_H_

#include "BinaryTreeNode.h"

class BinarySortTree
{
public:
	BinarySortTree();
	~BinarySortTree();

	/**
	 *  删除二叉排序树中的节点
	 */
	bool deleteBST(BinaryTreeNode *p, int elem);

	/**
	 * 二叉排序的插入算法
	 */
	bool insertBST(int elem);

	/**
	 * 在二叉树中查找相应的元素
	 * 这里f的初始值为nullptr
	 * 注意在为中间的参数设定缺省的初值的时候，后面的都要设定
	 */
	bool searchBST(int key, BinaryTreeNode *t, BinaryTreeNode *f = nullptr, BinaryTreeNode *p = nullptr);
private:
	/**
	 * 我们二叉排序树的根节点
	 */
	BinaryTreeNode *root;

	/**
	 * 在树中删除这个节点
	 */
	bool delNode(BinaryTreeNode *p);
};

#endif //_BINARY_SORT_TREE_H_

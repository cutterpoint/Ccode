/****************************************************************************
时间：2015年10月3日19:33:32
作者：cutter_point

文件：BinaryTreeNode.h

功能：二叉排序树的数据结构

****************************************************************************/

#ifndef _BSTNODE_H_
#define _BSTNODE_H_

class BSTNode
{
private:
	/**
	 * 二叉排序树节点的数据信息
	 */
	int data;

	/**
	 *  节点的平衡因子
	 */
	int bf;

	/**
	 *  节点的左右子树
	 */
	BSTNode *lchild, *rchild;
};

#endif //_BSTNODE_H_

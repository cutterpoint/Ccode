/****************************************************************************
时间：2015年10月3日19:33:32
作者：cutter_point

文件：BinaryTreeNode.h

功能：实现我们二叉树节点

****************************************************************************/
#include "BinaryTreeNode.h"


BinaryTreeNode::BinaryTreeNode()
{
	this->data = 0;
	this->lchild = this->rchild = nullptr;
}


BinaryTreeNode::~BinaryTreeNode()
{
	delete rchild;
	delete lchild;
}

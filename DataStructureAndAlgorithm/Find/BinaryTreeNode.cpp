/****************************************************************************
ʱ�䣺2015��10��3��19:33:32
���ߣ�cutter_point

�ļ���BinaryTreeNode.h

���ܣ�ʵ�����Ƕ������ڵ�

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

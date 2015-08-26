/****************************************************************************
时间：2015年8月24日17:13:47
作者：cutter_point

文件：BiThrNode.cpp

功能：实现我们的线索二叉树

****************************************************************************/

#include "stdafx.h"
#include "BiThrNode.h"


BiThrNode::BiThrNode()
{
	data = NULL;
	lchild = rchild =nullptr;
	LTag = RTag = PointerTag::Thread;
}


BiThrNode::~BiThrNode()
{
	delete lchild;
	delete rchild;
}

/****************************************************************************
时间：2015年9月16日19:08:04
作者：cutter_point

文件：CSNode.h

功能：实现我们的图的链式表示，邻接表，有向，无向都可以

****************************************************************************/

#include "stdafx.h"
#include "CSNode.h"


CSNode::CSNode()
{
	this->firstchild = nullptr;
	this->nextSibling = nullptr;
}


CSNode::~CSNode()
{
	delete firstchild;
	delete nextSibling;
}

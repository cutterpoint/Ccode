/****************************************************************************
ʱ�䣺2015��9��16��19:08:04
���ߣ�cutter_point

�ļ���CSNode.h

���ܣ�ʵ�����ǵ�ͼ����ʽ��ʾ���ڽӱ��������򶼿���

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

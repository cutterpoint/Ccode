/****************************************************************************
ʱ�䣺2015��8��24��17:13:47
���ߣ�cutter_point

�ļ���BiThrNode.cpp

���ܣ�ʵ�����ǵ�����������

****************************************************************************/

#include "stdafx.h"
#include "BiThrNode.h"


BiThrNode::BiThrNode()
{
}


BiThrNode::~BiThrNode()
{
	delete lchild;
	delete rchild;
}

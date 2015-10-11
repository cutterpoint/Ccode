/****************************************************************************
时间：2015年10月10日11:32:00
作者：cutter_point

文件：SqList.h

功能：实现内部排序的存储结构

****************************************************************************/

#include "stdafx.h"
#include "SqList.h"


SqList::SqList()
{
}


SqList::~SqList()
{
}

/**
 *  直接插入排序
 */
void SqList::insertSort(SqList *p)
{
	if (p == nullptr)
		return;
	//对顺序表p进行排序
	for (int i = 2; i < p->length; ++i)
	{
		//判断需不需要进行插入排序
		if (p->r[i] < p->r[i - 1])
		{
			//复制哨兵，我们0号元素，是不放数据的
			p->r[0] = p->r[i];
			p->r[i] = p->r[i - 1];
			//选择插入的位置
			int j = i - 2;
			for (; p->r[j] > p->r[0]; --j)
			{
				//后移
				p->r[j + 1] = p->r[j];
			}//for
			p->r[j + 1] = p->r[0];
		}//if
	}//for
}
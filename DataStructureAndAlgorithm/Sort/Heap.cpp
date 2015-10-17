/****************************************************************************
时间：2015年10月16日11:19:57
作者：cutter_point

文件：Heap.cpp

功能：堆排序

****************************************************************************/

#include "stdafx.h"
#include "Heap.h"


Heap::Heap()
{
	this->h = new SqList();
}


Heap::~Heap()
{
	delete h;
}

/**
 *  除了第s个，其他的都满足堆排序，调整第s号关键字，使成为大顶堆
 */
void Heap::heapAdjust(int s, int m)
{
	int rc = h->r[s];	//s是我们需要调整的数
	for (int j = 2 * s; j <= m; j *= 2)
	{
		//满足Ki < K2*i Ki < K2*i+1
		if (j < m && h->r[j] < h->r[j + 1])
		{
			//j是比较的大的那个的下标
			++j;
		}//if
		//如果是我们第s的值本身比我们后面2i或者2i+1大的那个还大，那么就是大于这两个
		if (rc >= h->r[j])
			break;
		//如果比较小的话，交换位置
		h->r[s] = h->r[j];
		s = j;
	}//for
	//最后把rc换回s
	h->r[s] = rc;
}

/**
 *  堆排序,0号不存元素
 */
void Heap::headSort()
{
	//不断对顺序表进行堆排序，然后选出堆顶元素，放到最后（大顶堆），结果就是每次大的都排到了最后
	//首先构建堆
	for (int i = h->length; i > 0; --i)
	{
		//不断进行堆调整
		this->heapAdjust(i, h->length);
	}//for

	int temp = 0;
	for (int i = h->length; i > 1; --i)
	{
		//把最大的放到最后
		temp = h->r[i];
		h->r[i] = h->r[1];
		h->r[1] = temp;

		//然后从新进行调整，但是不能有最后一个数据在内
		this->heapAdjust(1, i - 1);
	}//for
}
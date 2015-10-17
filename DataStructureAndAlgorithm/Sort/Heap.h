/****************************************************************************
时间：2015年10月16日11:19:01
作者：cutter_point

文件：Heap.h

功能：堆排序

****************************************************************************/

#ifndef _HEAP_H_
#define _HEAP_H_

#include "SqList.h"

class Heap
{
public:
	Heap();
	~Heap();

	/**
	 *  堆排序
	 */
	void headSort();
private:
	/**
	 *  存放堆的数据结构
	 */
	SqList *h;

	/**
	 *  除了第s个，其他的都满足堆排序，调整第s号关键字，使成为大顶堆
	 */
	void heapAdjust(int s, int m);
};

#endif //_HEAP_H_
/****************************************************************************
时间：2015年10月17日10:50:19
作者：cutter_point

文件：MergeSort.h

功能：关于归并排序

****************************************************************************/
#ifndef _MERGESORT_H_
#define _MERGESORT_H_

#include "SqList.h"

class MergeSort
{
public:
	MergeSort();
	~MergeSort();

	/**
	 *  归并排序
	 */
	void mergeSort(SqList &l);

private:
	/**
	 *  进行相应的归并排序，递归
	 */
	void mSort(int sr[], int tr1[], int s, int t);

	/**
	 *  第一个sr就是我们的等待排序的数据，排序结果放到tr中
	 *  从i开始到n结束，中间是m分开
	 */
	void merge(int sr[], int tr[], int i, int m, int n);
};

#endif //_MERGESORT_H_
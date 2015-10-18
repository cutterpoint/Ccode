/****************************************************************************
时间：2015年10月17日10:50:19
作者：cutter_point

文件：MergeSort.cpp

功能：关于归并排序

****************************************************************************/

#include "stdafx.h"
#include "MergeSort.h"


MergeSort::MergeSort()
{
}


MergeSort::~MergeSort()
{
}

/**
 *  第一个sr就是我们的等待排序的数据，排序结果放到tr中
 *  从i开始到n结束，中间是m分开
 */
void MergeSort::merge(int sr[], int tr[], int i, int m, int n)
{
	int j = m + 1;
	int k = i;
	for (; i <= m && j <= n; ++k)
	{
		//从头遍历到尾，进行排序
		if (sr[i] < sr[j])
		{
			//如果左边小，那么就把小的加入到tr中
			tr[k] = sr[i++];
		}//if
		else
		{
			tr[k] = sr[j++];
		}//else
	}//for

	//把剩下的部分加入到辅助数组中
	if (i <= m)
	{
		for (; i <= m; ++i)
		{
			tr[k] = sr[i];
			++k;
		}//for
	}//if

	if (j <= n)
	{
		for (; j <= n; ++j)
		{
			tr[k] = sr[j];
			++k;
		}//for
	}//if
}

/**
 *  进行相应的归并排序，递归
 */
void MergeSort::mSort(int sr[], int tr1[], int s, int t)
{
	//将sr[s..t]归并排序到tr1[s...t]
	if (s == t)
	{
		tr1[s] = sr[s];
	}//if
	else
	{
		//如果不等的话
		int m = (s + t) / 2;
		int *tr2 = new int[t - s + 1];
		mSort(sr, tr2, s, m);
		mSort(sr, tr2, m + 1, t);
		//合并tr2到tr1中
		merge(tr2, tr1, s, m, t);
	}//else
}

/**
 *  归并排序
 */
void MergeSort::mergeSort(SqList &l)
{
	if (l.length <= 0)
		return;
	//数组中有数据,0号元素不放数据
	this->mSort(l.r, l.r, 1, l.length - 1);
}

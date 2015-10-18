/****************************************************************************
时间：2015年10月10日11:32:00
作者：cutter_point

文件：SqList.h

功能：实现内部排序的存储结构

****************************************************************************/

#ifndef _SQLIST_H_
#define _SQLIST_H_

class Heap;

class SqList
{
	friend class Heap;
	friend class MergeSort;
public:
	const static int MAXSIZE = 200;
	SqList();
	~SqList();

	SqList(int *rr, int length)
	{
		if (length > MAXSIZE)
			return;
		for (int i = 0; i < length; ++i)
		{
			r[i] = rr[i];
		}//for
		this->length = length;
	}

	/**
	 *  直接插入排序
	 */
	void insertSort(SqList *p);

	/**
	 *  对顺序表的折半排序
	 */
	void bInsertSort(SqList *p);

	/**
	 *  快速排序
	 */
	void quikSort(SqList *p);

private:
	/**
	 *  存放数据的类型
	 *	r[0]用来空闲
	 */
	int r[MAXSIZE + 1];

	/**
	 *  顺序表的长度
	 */
	int length;

	/**
	 *  进行一次快排
	 */
	int partition(SqList *l, int low, int high);

	/**
	 *  交换两个数据
	 */
	void swap(SqList *l, int first, int second);

	/**
	 *  快排首先
	 */
	void quikSortCore(SqList *l, int low, int high);
};

#endif //_SQLIST_H_

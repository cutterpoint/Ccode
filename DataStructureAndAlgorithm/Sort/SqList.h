/****************************************************************************
时间：2015年10月10日11:32:00
作者：cutter_point

文件：SqList.h

功能：实现内部排序的存储结构

****************************************************************************/

#ifndef _SQLIST_H_
#define _SQLIST_H_

class SqList
{
public:
	const static int MAXSIZE = 20;
	SqList();
	~SqList();

	/**
	 *  直接插入排序
	 */
	void insertSort(SqList *p);

	/**
	 *  对顺序表的折半排序
	 */
	void bInsertSort(SqList *p);

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
};

#endif //_SQLIST_H_

/****************************************************************************
ʱ�䣺2015��10��10��11:32:00
���ߣ�cutter_point

�ļ���SqList.h

���ܣ�ʵ���ڲ�����Ĵ洢�ṹ

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
	 *  ֱ�Ӳ�������
	 */
	void insertSort(SqList *p);

	/**
	 *  ��˳�����۰�����
	 */
	void bInsertSort(SqList *p);

	/**
	 *  ��������
	 */
	void quikSort(SqList *p);

private:
	/**
	 *  ������ݵ�����
	 *	r[0]��������
	 */
	int r[MAXSIZE + 1];

	/**
	 *  ˳���ĳ���
	 */
	int length;

	/**
	 *  ����һ�ο���
	 */
	int partition(SqList *l, int low, int high);

	/**
	 *  ������������
	 */
	void swap(SqList *l, int first, int second);

	/**
	 *  ��������
	 */
	void quikSortCore(SqList *l, int low, int high);
};

#endif //_SQLIST_H_

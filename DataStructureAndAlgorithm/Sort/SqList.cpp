/****************************************************************************
ʱ�䣺2015��10��10��11:32:00
���ߣ�cutter_point

�ļ���SqList.h

���ܣ�ʵ���ڲ�����Ĵ洢�ṹ

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
 *  ֱ�Ӳ�������
 */
void SqList::insertSort(SqList *p)
{
	if (p == nullptr)
		return;
	//��˳���p��������
	for (int i = 2; i < p->length; ++i)
	{
		//�ж��費��Ҫ���в�������
		if (p->r[i] < p->r[i - 1])
		{
			//�����ڱ�������0��Ԫ�أ��ǲ������ݵ�
			p->r[0] = p->r[i];
			p->r[i] = p->r[i - 1];
			//ѡ������λ��
			int j = i - 2;
			for (; p->r[j] > p->r[0]; --j)
			{
				//����
				p->r[j + 1] = p->r[j];
			}//for
			p->r[j + 1] = p->r[0];
		}//if
	}//for
}

/**
 *  ��˳�����۰�����
 */
void SqList::bInsertSort(SqList *p)
{
	if (p == nullptr)
		return;
	//���������в�������,0�Ų��ò���
	for (int i = 2; i < p->length; ++i)
	{
		//�趨һ���ڱ�
		p->r[0] = p->r[i];
		//���Ҳ����λ��
		int low = 1, high = i - 1;
		while (low <= high)
		{
			//�۰�
			int m = (low + high) / 2;
			if (p->r[0] < p->r[m])
			{
				high = m - 1;
			}//if
			else
			{
				low = m + 1;
			}//if
		}//while

		//�ҵ�λ��֮�󣬺�������
		for (int j = i - 2; j >= high; --j)
			p->r[j + 1] = p->r[j];
		p->r[high + 1] = p->r[0];	//��������
	}//for
}

/**
 *  ����һ�ο���
 */
int SqList::partition(SqList *l, int low, int high)
{
	//������0��Ϊ��׼�����зֿ�
	l->r[0] = l->r[low];
	int key = l->r[0];
	while (low < high)
	{
		while (low < high && key <= l->r[high])
			--high;
		swap(l, low, high);
		while (low < high && key >= l->r[low])
			++low;
		swap(l, low, high);
	}//while
	l->r[low] = l->r[0];

	return low;
}

/**
 *  ������������
 */
void SqList::swap(SqList *l, int first, int second)
{
	if (first < 0 || first >= l->length || second < 0 || second >= l->length)
		return;

	int temp = l->r[first];
	l->r[first] = l->r[second];
	l->r[second] = temp;
}

/**
 *  ��������
 */
void SqList::quikSortCore(SqList *l, int low, int high)
{
	if (low < high)
	{
		int mid = partition(l, low, high);
		quikSortCore(l, low, mid - 1);
		quikSortCore(l, mid + 1, high);
	}//if
}

/**
 *  ��������
 */
void SqList::quikSort(SqList *p)
{
	if (p == nullptr)
		return;
	int low = 1, high = p->length - 1;
	quikSortCore(p, low, high);
}
/****************************************************************************
ʱ�䣺2015��10��17��10:50:19
���ߣ�cutter_point

�ļ���MergeSort.cpp

���ܣ����ڹ鲢����

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
 *  ��һ��sr�������ǵĵȴ���������ݣ��������ŵ�tr��
 *  ��i��ʼ��n�������м���m�ֿ�
 */
void MergeSort::merge(int sr[], int tr[], int i, int m, int n)
{
	int j = m + 1;
	int k = i;
	for (; i <= m && j <= n; ++k)
	{
		//��ͷ������β����������
		if (sr[i] < sr[j])
		{
			//������С����ô�Ͱ�С�ļ��뵽tr��
			tr[k] = sr[i++];
		}//if
		else
		{
			tr[k] = sr[j++];
		}//else
	}//for

	//��ʣ�µĲ��ּ��뵽����������
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
 *  ������Ӧ�Ĺ鲢���򣬵ݹ�
 */
void MergeSort::mSort(int sr[], int tr1[], int s, int t)
{
	//��sr[s..t]�鲢����tr1[s...t]
	if (s == t)
	{
		tr1[s] = sr[s];
	}//if
	else
	{
		//������ȵĻ�
		int m = (s + t) / 2;
		int *tr2 = new int[t - s + 1];
		mSort(sr, tr2, s, m);
		mSort(sr, tr2, m + 1, t);
		//�ϲ�tr2��tr1��
		merge(tr2, tr1, s, m, t);
	}//else
}

/**
 *  �鲢����
 */
void MergeSort::mergeSort(SqList &l)
{
	if (l.length <= 0)
		return;
	//������������,0��Ԫ�ز�������
	this->mSort(l.r, l.r, 1, l.length - 1);
}

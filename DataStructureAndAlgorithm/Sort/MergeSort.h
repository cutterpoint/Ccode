/****************************************************************************
ʱ�䣺2015��10��17��10:50:19
���ߣ�cutter_point

�ļ���MergeSort.h

���ܣ����ڹ鲢����

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
	 *  �鲢����
	 */
	void mergeSort(SqList &l);

private:
	/**
	 *  ������Ӧ�Ĺ鲢���򣬵ݹ�
	 */
	void mSort(int sr[], int tr1[], int s, int t);

	/**
	 *  ��һ��sr�������ǵĵȴ���������ݣ��������ŵ�tr��
	 *  ��i��ʼ��n�������м���m�ֿ�
	 */
	void merge(int sr[], int tr[], int i, int m, int n);
};

#endif //_MERGESORT_H_
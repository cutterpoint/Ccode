/****************************************************************************
ʱ�䣺2015��10��16��11:19:57
���ߣ�cutter_point

�ļ���Heap.cpp

���ܣ�������

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
 *  ���˵�s���������Ķ���������򣬵�����s�Źؼ��֣�ʹ��Ϊ�󶥶�
 */
void Heap::heapAdjust(int s, int m)
{
	int rc = h->r[s];	//s��������Ҫ��������
	for (int j = 2 * s; j <= m; j *= 2)
	{
		//����Ki < K2*i Ki < K2*i+1
		if (j < m && h->r[j] < h->r[j + 1])
		{
			//j�ǱȽϵĴ���Ǹ����±�
			++j;
		}//if
		//��������ǵ�s��ֵ���������Ǻ���2i����2i+1����Ǹ�������ô���Ǵ���������
		if (rc >= h->r[j])
			break;
		//����Ƚ�С�Ļ�������λ��
		h->r[s] = h->r[j];
		s = j;
	}//for
	//����rc����s
	h->r[s] = rc;
}

/**
 *  ������,0�Ų���Ԫ��
 */
void Heap::headSort()
{
	//���϶�˳������ж�����Ȼ��ѡ���Ѷ�Ԫ�أ��ŵ���󣨴󶥶ѣ����������ÿ�δ�Ķ��ŵ������
	//���ȹ�����
	for (int i = h->length; i > 0; --i)
	{
		//���Ͻ��жѵ���
		this->heapAdjust(i, h->length);
	}//for

	int temp = 0;
	for (int i = h->length; i > 1; --i)
	{
		//�����ķŵ����
		temp = h->r[i];
		h->r[i] = h->r[1];
		h->r[1] = temp;

		//Ȼ����½��е��������ǲ��������һ����������
		this->heapAdjust(1, i - 1);
	}//for
}
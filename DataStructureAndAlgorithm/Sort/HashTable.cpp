/****************************************************************************
ʱ�䣺2015��10��14��09:54:50
���ߣ�cutter_point

�ļ���HashTable.cpp

���ܣ���ϣ��Ĺ���

****************************************************************************/

#include "stdafx.h"
#include "HashTable.h"

Data::Data()
{}

Data::Data(int length, int ct = 0)
{
	this->sizeindex = length;
	this->elem = new int[sizeindex];
	for (int i = 0; i < sizeindex; ++i)
		elem[i] = -1;
	this->count = ct;
}

Data::~Data()
{
	delete[] elem;
}
/****************************************************************************/

HashTable::HashTable()
{
}


HashTable::~HashTable()
{
	delete h;
}

/**
 *  ��ϣ����
 */
int HashTable::hash(int k)
{
	int size = h->sizeindex;

	return k % size;
}

/**
 *  ����̽����ɢ��
 */
int HashTable::collision(int k, int c)
{
	return (k + c) % h->sizeindex;
}

int HashTable::searchHash(int k, int &c)
{
	int p = hash(k); int c = 0;
	while (h->elem[p] != -1 && h->elem[p] != k)
	{
		//���ʱ��������λ���Ѿ������ݣ����Ҳ���k
		p = collision(k, ++c);	//������һ��λ��
	}//while

	if (h->elem[p] == k)
	{
		//���ҳɹ�
		this->search_OK = 1;
	}//if
	else
	{
		//���Ҳ����������һ���µĿ�λ��
		this->search_OK = 0;
	}//else

	return p;
}

/**
 *  ��ϣ��Ĳ����㷨
 */
int HashTable::insertHash(int e)
{
	int c = 0;
	int p = searchHash(e, c);
	if (this->search_OK == 1)
	{
		//�Ѿ�����
		return -1;
	}//if
	else if (c < h->sizeindex / 2)
	{
		//��������
		h->elem[p] = e;
		++h->count;
		return 1;
	}//else if
	else
	{
		//��Ҫ�ؽ���ϣ��
		return -1;
	}//else
}

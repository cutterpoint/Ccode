/****************************************************************************
时间：2015年10月14日09:54:50
作者：cutter_point

文件：HashTable.cpp

功能：哈希表的构建

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
 *  哈希函数
 */
int HashTable::hash(int k)
{
	int size = h->sizeindex;

	return k % size;
}

/**
 *  线性探测在散列
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
		//这个时候就是这个位置已经有数据，并且不是k
		p = collision(k, ++c);	//查找下一个位置
	}//while

	if (h->elem[p] == k)
	{
		//查找成功
		this->search_OK = 1;
	}//if
	else
	{
		//查找不到，这个是一个新的空位置
		this->search_OK = 0;
	}//else

	return p;
}

/**
 *  哈希表的插入算法
 */
int HashTable::insertHash(int e)
{
	int c = 0;
	int p = searchHash(e, c);
	if (this->search_OK == 1)
	{
		//已经存在
		return -1;
	}//if
	else if (c < h->sizeindex / 2)
	{
		//插入数据
		h->elem[p] = e;
		++h->count;
		return 1;
	}//else if
	else
	{
		//需要重建哈希表
		return -1;
	}//else
}

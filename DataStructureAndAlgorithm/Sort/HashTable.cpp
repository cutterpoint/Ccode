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

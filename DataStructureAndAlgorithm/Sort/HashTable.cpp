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

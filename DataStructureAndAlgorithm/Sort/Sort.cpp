// Sort.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "SqList.h"
#include <iostream>

using namespace std;

void test()
{
	int l[8] = {0,49,38,65,97,76,13,27};
	SqList *p = new SqList(l, 8);
	p->quikSort(p);
	int j = 0;
}

void test2()
{
}

int _tmain(int argc, _TCHAR* argv[])
{
	test();
	return 0;
}


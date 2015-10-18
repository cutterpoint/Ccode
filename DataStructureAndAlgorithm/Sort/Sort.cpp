// Sort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "SqList.h"
#include "MergeSort.h"
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
	MergeSort *ms = new MergeSort();
	int l[8] = { 0, 49, 38, 65, 97, 76, 13, 27 };
	SqList *p = new SqList(l, 8);
	ms->mergeSort(*p);
}

int _tmain(int argc, _TCHAR* argv[])
{
	//test();
	test2();
	return 0;
}


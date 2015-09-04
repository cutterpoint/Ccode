/****************************************************************************
时间：2015年8月31日16:59:02
作者：cutter_point

文件：main.cpp

功能：实现我们的各种图的操作

****************************************************************************/

#include "stdafx.h"
#include "MGraphUDN.h"

#include <iostream>

using namespace std;

void Test()
{
	MGraphUDN *G = new MGraphUDN("source1.txt");
	G->createUDN();
	//输出矩阵
	G->printMaxtrix();
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test();
	return 0;
}


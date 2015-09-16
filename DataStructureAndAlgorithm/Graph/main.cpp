/****************************************************************************
时间：2015年8月31日16:59:02
作者：cutter_point

文件：main.cpp

功能：实现我们的各种图的操作

****************************************************************************/

#include "stdafx.h"
#include "MGraphUDN.h"
#include "MGraphDG.h"
#include "MGraphAL.h"

#include <iostream>

using namespace std;

void Test1()
{
	MGraphUDN *G = new MGraphUDN("resource1.txt");
	G->createUDN();
	//输出矩阵
	G->printMaxtrix();
}

void Test2()
{
	MGraphDG *G = new MGraphDG("resource2.txt");
	cout << endl;
	MGraphAL *GAL = new MGraphAL();
	GAL->create("resource3.txt");
	cout << "深度优先" << endl;
	GAL->DFSTraverse();
	cout << "\n广度优先" << endl;
	GAL->BFSTraverse();
	cout << "\n兄弟链表表示" << endl;
	GAL->DFSForest();
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test1();
	Test2();
	return 0;
}


/****************************************************************************
ʱ�䣺2015��8��31��16:59:02
���ߣ�cutter_point

�ļ���main.cpp

���ܣ�ʵ�����ǵĸ���ͼ�Ĳ���

****************************************************************************/

#include "stdafx.h"
#include "MGraphUDN.h"
#include "MGraphDG.h"
#include "MGraphAL.h"

#include <iostream>

using namespace std;

void Test1()
{
	MGraphUDN *G = new MGraphUDN("resource5.txt");
	G->createUDN();
	//�������
	G->printMaxtrix();
	//�����С������
	G->miniSpanTree_PRIM("v1");//������ʾ���Ǹ����㿪ʼ
}

void Test2()
{
	MGraphDG *G = new MGraphDG("resource2.txt");
	cout << endl;
	MGraphAL *GAL = new MGraphAL();
	GAL->create("resource3.txt");
	cout << "�������" << endl;
	GAL->DFSTraverse();
	cout << "\n�������" << endl;
	GAL->BFSTraverse();
	cout << "\n�ֵ������ʾ" << endl;
	GAL->DFSForest();
	cout << "\n������������" << endl;
	GAL->topologicalSort();
	cout << "\n��ؼ�·��" << endl;
	MGraphAL *GAL2 = new MGraphAL();
	GAL2->createWithWeight("resource4.txt");
	GAL2->criticalPath();
	cout << "\n������������" << endl;
	GAL2->topologicalSort();
}


int _tmain(int argc, _TCHAR* argv[])
{
	Test1();
	cout << "===============================================" << endl;
	cout << "===============================================" << endl;
	cout << "===============================================" << endl;
	Test2();
	return 0;
}


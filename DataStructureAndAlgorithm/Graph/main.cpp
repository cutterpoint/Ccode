/****************************************************************************
ʱ�䣺2015��8��31��16:59:02
���ߣ�cutter_point

�ļ���main.cpp

���ܣ�ʵ�����ǵĸ���ͼ�Ĳ���

****************************************************************************/

#include "stdafx.h"
#include "MGraphUDN.h"
#include "MGraphDG.h"

#include <iostream>

using namespace std;

void Test1()
{
	MGraphUDN *G = new MGraphUDN("resource1.txt");
	G->createUDN();
	//�������
	G->printMaxtrix();
}

void Test2()
{
	MGraphDG *G = new MGraphDG("resource2.txt");
	cout << "!!" << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test1();
	Test2();
	return 0;
}


/****************************************************************************
ʱ�䣺2015��8��31��16:59:02
���ߣ�cutter_point

�ļ���main.cpp

���ܣ�ʵ�����ǵĸ���ͼ�Ĳ���

****************************************************************************/

#include "stdafx.h"
#include "MGraphUDN.h"

#include <iostream>

using namespace std;

void Test1()
{
	MGraphUDN *G = new MGraphUDN("resource1.txt");
	G->createUDN();
	//�������
	G->printMaxtrix();
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test1();
	return 0;
}


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

void Test()
{
	MGraphUDN *G = new MGraphUDN("source1.txt");
	G->createUDN();
	//�������
	G->printMaxtrix();
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test();
	return 0;
}


/****************************************************************************
ʱ�䣺2015��8��29��16:12:09
���ߣ�cutter_point

�ļ���main.cpp

���ܣ�ʵ�����ǵĹ���������

****************************************************************************/
#include "stdafx.h"
#include "HuffmanTree.h"

#include <iostream>

using namespace std;

void Test()
{
	int w[] = {5,29,7,8,14,23,3,11};
	HuffmanTree *ht = new HuffmanTree();
	ht->huffmanInit(w, 8);
	ht->printTree(15);
	ht->createHuffmanCode(8);
	ht->printCode(8);
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test();
	return 0;
}


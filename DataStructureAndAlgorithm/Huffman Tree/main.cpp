/****************************************************************************
时间：2015年8月29日16:12:09
作者：cutter_point

文件：main.cpp

功能：实现我们的哈夫曼编码

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


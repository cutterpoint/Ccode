// Threaded BinaryTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "BiThrNode.h"
#include "BiThr.h"

void Test()
{
	BiThr *bt = new BiThr();
	char preOrder[] = { '-', '+', 'a', '*', 'b', 'c', '/', 'd', 'e' };
	char inOrder[] = { 'a', '+', 'b', '*', 'c', '-', 'd', '/', 'e' };
	bt->createBiThr(preOrder, inOrder, 9);
	bt->inOrderThreading();	//线索化
	bt->inOrderTraverse_Thr();	//遍历
}


int _tmain(int argc, _TCHAR* argv[])
{
	Test();
	return 0;
}


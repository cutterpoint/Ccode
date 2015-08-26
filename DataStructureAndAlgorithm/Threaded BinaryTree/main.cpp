// Threaded BinaryTree.cpp : �������̨Ӧ�ó������ڵ㡣
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
	bt->inOrderThreading();	//������
	bt->inOrderTraverse_Thr();	//����
}


int _tmain(int argc, _TCHAR* argv[])
{
	Test();
	return 0;
}


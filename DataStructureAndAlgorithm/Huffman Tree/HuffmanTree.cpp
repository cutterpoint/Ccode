/****************************************************************************
时间：2015年8月28日16:41:21
作者：cutter_point

文件：HuffmanTree.cpp

功能：实现我们的哈夫曼编码

****************************************************************************/

#include "stdafx.h"
#include "HuffmanTree.h"


HuffmanTree::HuffmanTree()
{
}


HuffmanTree::~HuffmanTree()
{
	//回收二维数组
	char **p = huffmanCode;
	while (p != nullptr)
	{
		char **q = p;
		p = p + 1;
		delete[] *q;
	}

	delete[] huffmanCode;
	//回收二叉树，线性表
	delete[] huffmanTree;
}

/**
* 在哈夫曼树中查找到最小的两个数，并且这两个数的parent为0
*/
void HuffmanTree::select(int start, int end, int *s1, int *s2)
{
	int min1 = 0, min2 = 0;
	int i = start, num = 1;
	while (i <= end)
	{
		//我们用num来控制来对那个min进行赋值
		if (huffmanTree[i].parent == 0)
		{
			if (num == 1)
			{
				min1 = i;
				++num;
			}//if
			else if (num == 2)
			{
				min2 = i;
				++num;
			}//else if
			else
				break;
		}//if
	}//while

	//如果我们最后只剩下一个parent为0的数了，说明就是只剩下根了
	if (num != 3)
		return;

	//查找最小的两个数
	for (; i <= end; ++i)
	{
		//排除已经有parent的数，这种数，已经中和了
		if (huffmanTree[i].weight < huffmanTree[min2].weight && huffmanTree[i].parent == 0)
		{
			if (huffmanTree[i].weight < huffmanTree[min1].weight)
			{
				//这个是比当前两个最小的还小
				min2 = min1;
				min1 = i;
			}//if
			else
			{
				min2 = i;
			}//else
		}//if
	}//for

	*s1 = min1;
	*s2 = min2;
}


/**
* 初始化我们的哈夫曼树，建立基于线性表的哈夫曼树
* @param int *w 我们的权重数组
* @param int n 我们数组数据的个数
*/
void HuffmanTree::huffmanInit(int *w, int n)
{
	//鲁棒性检查
	if (n <= 1 || w == nullptr)
		return;
	//我们二叉树需要的数组长度
	int m = 2 * n - 1;
}


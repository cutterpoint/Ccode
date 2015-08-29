/****************************************************************************
时间：2015年8月28日16:41:21
作者：cutter_point

文件：HuffmanTree.cpp

功能：实现我们的哈夫曼编码

****************************************************************************/

#include "stdafx.h"
#include "HuffmanTree.h"

#include <string>


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
		++i;
	}//while

	//如果我们最后只剩下一个parent为0的数了，说明就是只剩下根了
	if (num != 3)
		return;
	//这里交换一下min1和min2的大小
	if (huffmanTree[min1].weight > huffmanTree[min2].weight)
	{
		int temp = min1;
		min1 = min2;
		min2 = temp;
	}

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
	huffmanTree = new HuffmanNode[m + 1];
	//用一个变量计数，我们给数组赋值到了上面位置
 	int i = 1;
	for (HuffmanNode *p = huffmanTree + 1; i <= n; ++i, ++p)
	{
		p->weight = w[i - 1];
	}//for

	//进行后面的合并
	//++i;
	for (; i <= m; ++i)
	{
		int s1 = 0, s2 = 0;	//用来放当前数组中最小的两个数的位置
		select(1, i - 1, &s1, &s2);
		huffmanTree[s1].parent = i;
		huffmanTree[s2].parent = i;
		huffmanTree[i].lchild = s1;
		huffmanTree[i].rchild = s2;
		huffmanTree[i].weight = huffmanTree[s1].weight + huffmanTree[s2].weight;
	}//for
}

/**
* 对我们的哈夫曼树进行编码的生成
*/
void HuffmanTree::createHuffmanCode(int n)
{
	huffmanCode = new char*[n + 1];	//动态分配指针数组
	char *cd = new char[n];
	cd[n - 1] = '\0';
	for (int i = 1; i <= n; ++i)
	{
		int start = n - 1;
		//f代表父节点的位置，c代表当前节点
		for (int c = i, f = huffmanTree[i].parent; f != 0; c = f, f = huffmanTree[f].parent)
		{
			if (huffmanTree[f].lchild == c)
			{
				cd[--start] = '0';
			}//if
			else
			{
				cd[--start] = '1';
			}//else
		}//for
		huffmanCode[i] = new char[n - start];
		strcpy(huffmanCode[i], &cd[start]);	//第二个参数是引用
	}//for
	delete[] cd;
}

/**
* 输出我们的数
*/
void HuffmanTree::printTree(int n)
{
	HuffmanNode *p = huffmanTree;
	++p;
	for (int i = 1; i <= n; ++i, ++p)
	{
		printf("%d\t", p->weight);
	}
}

/**
* 输出我们的编码
*/
void HuffmanTree::printCode(int n)
{
	for (int i = 1; i <= n; ++i)
	{
		char *temp = huffmanCode[i];
		printf("第%d个字符的编码是：", i);
		while (*temp != '\0')
			printf("%c", *temp++);
		printf("\n");
	}//for
}

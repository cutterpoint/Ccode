/****************************************************************************
ʱ�䣺2015��8��28��16:41:21
���ߣ�cutter_point

�ļ���HuffmanTree.cpp

���ܣ�ʵ�����ǵĹ���������

****************************************************************************/

#include "stdafx.h"
#include "HuffmanTree.h"

#include <string>


HuffmanTree::HuffmanTree()
{
}


HuffmanTree::~HuffmanTree()
{
	//���ն�ά����
	char **p = huffmanCode;
	while (p != nullptr)
	{
		char **q = p;
		p = p + 1;
		delete[] *q;
	}

	delete[] huffmanCode;
	//���ն����������Ա�
	delete[] huffmanTree;
}

/**
* �ڹ��������в��ҵ���С������������������������parentΪ0
*/
void HuffmanTree::select(int start, int end, int *s1, int *s2)
{
	int min1 = 0, min2 = 0;
	int i = start, num = 1;
	while (i <= end)
	{
		//������num�����������Ǹ�min���и�ֵ
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

	//����������ֻʣ��һ��parentΪ0�����ˣ�˵������ֻʣ�¸���
	if (num != 3)
		return;
	//���ｻ��һ��min1��min2�Ĵ�С
	if (huffmanTree[min1].weight > huffmanTree[min2].weight)
	{
		int temp = min1;
		min1 = min2;
		min2 = temp;
	}

	//������С��������
	for (; i <= end; ++i)
	{
		//�ų��Ѿ���parent���������������Ѿ��к���
		if (huffmanTree[i].weight < huffmanTree[min2].weight && huffmanTree[i].parent == 0)
		{
			if (huffmanTree[i].weight < huffmanTree[min1].weight)
			{
				//����Ǳȵ�ǰ������С�Ļ�С
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
* ��ʼ�����ǵĹ��������������������Ա�Ĺ�������
* @param int *w ���ǵ�Ȩ������
* @param int n �����������ݵĸ���
*/
void HuffmanTree::huffmanInit(int *w, int n)
{
	//³���Լ��
	if (n <= 1 || w == nullptr)
		return;
	//���Ƕ�������Ҫ�����鳤��
	int m = 2 * n - 1;
	huffmanTree = new HuffmanNode[m + 1];
	//��һ���������������Ǹ����鸳ֵ��������λ��
 	int i = 1;
	for (HuffmanNode *p = huffmanTree + 1; i <= n; ++i, ++p)
	{
		p->weight = w[i - 1];
	}//for

	//���к���ĺϲ�
	//++i;
	for (; i <= m; ++i)
	{
		int s1 = 0, s2 = 0;	//�����ŵ�ǰ��������С����������λ��
		select(1, i - 1, &s1, &s2);
		huffmanTree[s1].parent = i;
		huffmanTree[s2].parent = i;
		huffmanTree[i].lchild = s1;
		huffmanTree[i].rchild = s2;
		huffmanTree[i].weight = huffmanTree[s1].weight + huffmanTree[s2].weight;
	}//for
}

/**
* �����ǵĹ����������б��������
*/
void HuffmanTree::createHuffmanCode(int n)
{
	huffmanCode = new char*[n + 1];	//��̬����ָ������
	char *cd = new char[n];
	cd[n - 1] = '\0';
	for (int i = 1; i <= n; ++i)
	{
		int start = n - 1;
		//f�����ڵ��λ�ã�c����ǰ�ڵ�
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
		strcpy(huffmanCode[i], &cd[start]);	//�ڶ�������������
	}//for
	delete[] cd;
}

/**
* ������ǵ���
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
* ������ǵı���
*/
void HuffmanTree::printCode(int n)
{
	for (int i = 1; i <= n; ++i)
	{
		char *temp = huffmanCode[i];
		printf("��%d���ַ��ı����ǣ�", i);
		while (*temp != '\0')
			printf("%c", *temp++);
		printf("\n");
	}//for
}

/****************************************************************************
ʱ�䣺2015��8��28��16:41:21
���ߣ�cutter_point

�ļ���HuffmanTree.cpp

���ܣ�ʵ�����ǵĹ���������

****************************************************************************/

#include "stdafx.h"
#include "HuffmanTree.h"


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
	}//while

	//����������ֻʣ��һ��parentΪ0�����ˣ�˵������ֻʣ�¸���
	if (num != 3)
		return;

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
}


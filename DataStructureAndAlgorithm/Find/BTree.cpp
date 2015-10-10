/****************************************************************************
ʱ�䣺2015��10��9��10:46:47
���ߣ�cutter_point

�ļ���BTree.cpp

���ܣ�B-��

****************************************************************************/

#include "BTree.h"


BTree::BTree()
{
}


BTree::~BTree()
{
	delete root;
}

/**
 *  ��������ڵ�ؼ����������Ƿ���������Ҫ���������
 */
int BTree::search(BTNode *p, int k)
{
	if (p == nullptr)
		return 0;
	//�������ǽ��ж��ֲ���
	int start = 1, end = p->m;
	int mid = (start + end) / 2;
	while (start < end)
	{
		if (k == p->key[mid])
		{
			return mid;
		}//if
		else if (k > p->key[mid])
		{
			start = mid + 1;
			mid = (start + end) / 2;
		}//else if
		else
		{
			end = mid - 1;
		}//else
	}//while

	if (start >= end)
		return 0;
}

/**
 *  B-���Ĳ��Ҳ�����ʵ��
 */
Result* BTree::searchBTree(int k)
{
	BTNode *p = root, *q = nullptr;
	bool found = false;	int i = 0;
	while (p != nullptr && !found)
	{
		//���ҵ���Ӧ������,�������е��±�
		int i = this->search(p, k);
		if (i > 0 && p->key[i] == k)
		{
			found = true;
		}//if
		else
		{
			q = p; p = p->ptr[i];
		}//else
	}//while

	if (found)
	{
		return new Result(p, i, 1);
	}//if
	else
	{
		return new Result(q, i, 0);
	}//else
}

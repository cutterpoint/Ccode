/****************************************************************************
时间：2015年10月9日10:46:47
作者：cutter_point

文件：BTree.cpp

功能：B-树

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
 *  查找这个节点关键字向量中是否含有我们需要的这个数据
 */
int BTree::search(BTNode *p, int k)
{
	if (p == nullptr)
		return 0;
	//这里我们进行二分查找
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
 *  B-树的查找操作的实现
 */
Result* BTree::searchBTree(int k)
{
	BTNode *p = root, *q = nullptr;
	bool found = false;	int i = 0;
	while (p != nullptr && !found)
	{
		//查找到相应的数据,在数组中的下标
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

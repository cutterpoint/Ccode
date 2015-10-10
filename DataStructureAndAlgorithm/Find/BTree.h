/****************************************************************************
时间：2015年10月9日10:46:47
作者：cutter_point

文件：BTree.h

功能：B-树

****************************************************************************/

#ifndef _BTREE_H_
#define _BTREE_H_

#include "BTNode.h"

class BTree
{
public:
	BTree();
	~BTree();

	/**
	 *  B-树的查找操作的实现
	 */
	Result* searchBTree(int k);

private:
	BTNode *root;

	/**
	 *  查找这个节点关键字向量中是否含有我们需要的这个数据
	 */
	int search(BTNode *p, int k);
};

#endif //_BTREE_H_


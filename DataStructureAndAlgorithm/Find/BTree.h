/****************************************************************************
ʱ�䣺2015��10��9��10:46:47
���ߣ�cutter_point

�ļ���BTree.h

���ܣ�B-��

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
	 *  B-���Ĳ��Ҳ�����ʵ��
	 */
	Result* searchBTree(int k);

private:
	BTNode *root;

	/**
	 *  ��������ڵ�ؼ����������Ƿ���������Ҫ���������
	 */
	int search(BTNode *p, int k);
};

#endif //_BTREE_H_


/****************************************************************************
ʱ�䣺2015��10��3��19:29:38
���ߣ�cutter_point

�ļ���BinarySortTree.h

���ܣ�ʵ�����ǵĲ��ҵĶ���������

****************************************************************************/

#ifndef _BINARY_SORT_TREE_H_
#define _BINARY_SORT_TREE_H_

#include "BinaryTreeNode.h"

class BinarySortTree
{
public:
	BinarySortTree();
	~BinarySortTree();

	/**
	 * ��������Ĳ����㷨
	 */
	bool insertBST(int elem);

	/**
	 * �ڶ������в�����Ӧ��Ԫ��
	 * ����f�ĳ�ʼֵΪnullptr
	 * ע����Ϊ�м�Ĳ����趨ȱʡ�ĳ�ֵ��ʱ�򣬺���Ķ�Ҫ�趨
	 */
	bool searchBST(int key, BinaryTreeNode *t, BinaryTreeNode *f = nullptr, BinaryTreeNode *p = nullptr);
private:
	/**
	 * ���Ƕ����������ĸ��ڵ�
	 */
	BinaryTreeNode *root;
};

#endif //_BINARY_SORT_TREE_H_

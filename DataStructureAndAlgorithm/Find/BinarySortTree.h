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
	 *  ɾ�������������еĽڵ�
	 */
	bool deleteBST(BinaryTreeNode *p, int elem);

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

	/**
	 * ������ɾ������ڵ�
	 */
	bool delNode(BinaryTreeNode *p);
};

#endif //_BINARY_SORT_TREE_H_

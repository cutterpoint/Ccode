/****************************************************************************
ʱ�䣺2015��8��24��17:13:47
���ߣ�cutter_point

�ļ���BiThr.h

���ܣ�ʵ�����ǵ�����������

****************************************************************************/
#ifndef _Tree_BITHR_
#define _Tree_BITHR_

#include "BiThrNode.h"

class BiThr
{
public:
	BiThr();
	~BiThr();

	/**
	 * ��������������,ǰ�������
	 */
	void createBiThr(char *preOrder, char *inOrder, int length);

	/**
	 * Ϊ������������ӽڵ�,Ԫ��
	 */
	void addBiThrNode(char elem);

	/***
	 *  ɾ�������������ڵ�
	 */
	BiThrNode *deleteBiThrNode(char elem);

	/**
	 *  ����������������������
	 */
	void inOrderThreading();

	/**
	 * ���������������б���
	 */
	void inOrderTraverse_Thr();

private:
	/**
	 * ���ǵ�ͷ����ǿյģ����ָ�����Ƕ������ĸ����ұ�ָ�������������ʱ���ʵ����һ���ڵ�
	 */
	BiThrNode *Thrt;

	/**
	 * ��������ʱ��������һ��ָ��ָ�����ǵ�ǰ���ڵ�(����)
	 */
	BiThrNode *pre;

	/**
	 * �Զ���������������ʱʹ�õ��ģ��������������
	 */
	void inThreading(BiThrNode *treeNode);

	/**
	 * ���ǽ���һ����������������һ���ڵ������
	 */
	void visit(BiThrNode *p);

	/**
	 *���ǵĶ�������������
	 *@param  int *startPreorder  ǰ������ĵ�һ���ڵ��ָ��
	 *@param  int *endPreorder  ǰ����������һ���ڵ��ָ��
	 *@param  int *startInorder  ��������ĵ�һ���ڵ��ָ��
	 *@param  int *endInorder  ������������һ���ڵ��ָ��
	 *@return BinaryTreeNode* �������ǵĸ��ڵ�
	 */
	BiThrNode *constructCore(char *startPreorder, char *endPreorder, char *startInorder, char *endInorder);
};

#endif /*_Tree_BITHR_*/
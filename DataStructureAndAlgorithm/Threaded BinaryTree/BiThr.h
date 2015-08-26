/****************************************************************************
时间：2015年8月24日17:13:47
作者：cutter_point

文件：BiThr.h

功能：实现我们的线索二叉树

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
	 * 创建线索二叉树,前序和中序
	 */
	void createBiThr(char *preOrder, char *inOrder, int length);

	/**
	 * 为线索二叉树添加节点,元素
	 */
	void addBiThrNode(char elem);

	/***
	 *  删除线索二叉树节点
	 */
	BiThrNode *deleteBiThrNode(char elem);

	/**
	 *  把线索二叉树进行线索化
	 */
	void inOrderThreading();

	/**
	 * 对线索二叉树进行遍历
	 */
	void inOrderTraverse_Thr();

private:
	/**
	 * 我们的头结点是空的，左边指向我们二叉树的根，右边指向我们中序遍历时访问的最后一个节点
	 */
	BiThrNode *Thrt;

	/**
	 * 线索化的时候我们有一个指针指向我们的前驱节点(中序)
	 */
	BiThrNode *pre;

	/**
	 * 对二叉树进行线索化时使用到的，中序遍历二叉树
	 */
	void inThreading(BiThrNode *treeNode);

	/**
	 * 我们建立一个函数，用来访问一个节点的内容
	 */
	void visit(BiThrNode *p);

	/**
	 *我们的二叉树构建函数
	 *@param  int *startPreorder  前序遍历的第一个节点的指针
	 *@param  int *endPreorder  前序遍历的最后一个节点的指针
	 *@param  int *startInorder  中序遍历的第一个节点的指针
	 *@param  int *endInorder  中序遍历的最后一个节点的指针
	 *@return BinaryTreeNode* 返回我们的根节点
	 */
	BiThrNode *constructCore(char *startPreorder, char *endPreorder, char *startInorder, char *endInorder);
};

#endif /*_Tree_BITHR_*/
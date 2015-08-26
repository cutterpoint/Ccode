/****************************************************************************
ʱ�䣺2015��8��24��17:13:47
���ߣ�cutter_point

�ļ���BiThr.cpp

���ܣ�ʵ�����ǵ�����������

****************************************************************************/

#include "stdafx.h"
#include "BiThr.h"

#include <iostream>

BiThr::BiThr()
{
}


BiThr::~BiThr()
{
	delete this->Thrt;
}

/**
*���ǵĶ�������������
*@param  int *startPreorder  ǰ������ĵ�һ���ڵ��ָ��
*@param  int *endPreorder  ǰ����������һ���ڵ��ָ��
*@param  int *startInorder  ��������ĵ�һ���ڵ��ָ��
*@param  int *endInorder  ������������һ���ڵ��ָ��
*@return BinaryTreeNode* �������ǵĸ��ڵ�
*/
BiThrNode* BiThr::constructCore(char *startPreorder, char *endPreorder, char *startInorder, char *endInorder)
{
	char value = *startPreorder;
	//��������Ϊ��ǰ�Ľڵ㴴��һ������
	BiThrNode *btn = new BiThrNode();
	btn->data = value;
	btn->lchild = btn->rchild = nullptr;
	btn->LTag = btn->RTag = BiThrNode::PointerTag::Thread;

	//�����������ǵĵݹ���ֹ����
	if (startPreorder == endPreorder)
	{
		if (startInorder == endInorder && *startPreorder == *startInorder)
		{
			//OK������Ѿ���Ҷ�ӽڵ���
			return btn;
		}
		else
		{
			throw std::exception("ǰ���������������в�ƥ��");
		}
	}//if

	char *rootInorder = startInorder;
	//���������ҵ���ǰ��,Ҳ����btn
	while (rootInorder <= endInorder && *rootInorder != value)
	{
		++rootInorder;
	}//while

	//���ǿ������ҵ��ˣ����ǵ���ĩβ
	if (rootInorder > endInorder && *rootInorder != value)
	{
		throw std::exception("���ݲ�ƥ�䣬�����γ�Ψһ������");
	}//if

	//�ݹ�
	int leftlength = rootInorder - startInorder;	//�����������������
	if (leftlength > 0)
	{
		btn->LTag = BiThrNode::PointerTag::Link;
		btn->lchild = this->constructCore(startPreorder + 1, startPreorder + leftlength, startInorder, rootInorder - 1);
	}
	//�ұ�,�ұ��������Ԫ�صĻ�
	if ((endInorder - rootInorder) > 0)
	{
		btn->RTag = BiThrNode::PointerTag::Link;
		btn->rchild = constructCore(startPreorder + leftlength + 1, endPreorder, rootInorder + 1, endInorder);
	}

	//���ظ�
	return btn;
}

/**
* ��������������������ǰ��
*/
void BiThr::createBiThr(char *preOrder, char *inOrder, int length)
{
	if (preOrder == nullptr || inOrder == nullptr || length <= 0)
	{
		this->Thrt = nullptr;
	}//if

	//���ǰѽڵ㷵��
	this->Thrt = constructCore(preOrder, preOrder + length - 1, inOrder, inOrder + length - 1);
}

/**
* ���ǽ���һ����������������һ���ڵ������
*/
void BiThr::visit(BiThrNode *p)
{
	std::cout << "��Tag-����-��Tag" << std::endl << p->LTag << "-" << p->data << "-" << p->RTag << std::endl;
}

/**
* �Զ���������������ʱʹ�õ��ģ��������������
*/
void BiThr::inThreading(BiThrNode *treeNode)
{
	//���ǵݹ����������������������
	if (treeNode != nullptr)
	{
		//������������ȱ���������
		inThreading(treeNode->lchild);
		if (treeNode == nullptr)
		{
			//�������ĵݹ����������Ҷ�ӽڵ㣬��������Ѿ��ǿսڵ��ˣ���ô���ǾͰ���������������ָ��ǰ��
			treeNode->lchild = pre;
			treeNode->LTag = BiThrNode::PointerTag::Thread;
		}//if
		//���趨�µ�ǰ��֮ǰ������ǰ��һ��ǰ���ĺ�̾��ǵ�ǰ�Ľڵ�
		if (pre->rchild == nullptr)
		{
			pre->rchild = treeNode;
			pre->LTag = BiThrNode::PointerTag::Thread;
		}//if
		//��߽������м�
		pre = treeNode;

		//����ұ�
		inThreading(treeNode->rchild);
	}//if
}

/**
*  ����������������������
*/
void BiThr::inOrderThreading()
{
	//�����ȴ���һ���յ�ͷ��㣬�������ָ�����ǵĶ������ĸ����ұ�ָ�����һ��Ԫ��
	BiThrNode *pHead = new BiThrNode();
	pHead->LTag = BiThrNode::PointerTag::Link;
	pHead->rchild = pHead;	//����ʱ���ұ�ָ���Լ���Ϊ���ǲ�֪�����������Ƿ����
	pHead->RTag = BiThrNode::PointerTag::Thread;
	//�������ж϶������Ƿ����
	if (Thrt == nullptr)
	{
		//���������������
		pHead->lchild = pHead;	//ȫ��ָ���Լ�
	}//if
	else
	{
		pre = pHead;	//�ʼ��ǰ�������ǿյ�ͷ�ڵ�
		pHead->lchild = Thrt;	//���ָ���
		inThreading(Thrt);	//�Ѷ���������������
		//������ǵ�ǰ��(pre)��������֮��ָ����Ǳ���������������һ���ڵ�
		pre->rchild = pHead;
		pre->RTag = BiThrNode::PointerTag::Thread;
		//������ǵ�ͷ�����ұ�ָ�����һ���������Ľڵ�
		pHead->rchild = pre;
	}//else

	//���õ��µ�ͷ���
	Thrt = pHead;
}

/**
* ���������������б���
*/
void BiThr::inOrderTraverse_Thr()
{
	BiThrNode *p = Thrt->lchild;	//���ڵ�
	while (p != Thrt)
	{
		while (p->LTag == BiThrNode::PointerTag::Link)
		{
			p = p->lchild;
		}//while
		visit(p);	//���ʵ�ǰ�ڵ�
		while (p->RTag == BiThrNode::PointerTag::Thread && p->rchild != Thrt)
		{
			//���ǰѺ�̵�����ȫ�������ˣ�֮�������ڻص����ǵĶ�����
			p = p->rchild;
			visit(p);
		}//while
		p = p->rchild;
	}//while
}


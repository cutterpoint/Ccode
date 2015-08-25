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
		btn->lchild = this->constructCore(startPreorder + 1, startPreorder + leftlength, startInorder, rootInorder - 1);
		btn->LTag = BiThrNode::PointerTag::Link;
	}
	//�ұ�,�ұ��������Ԫ�صĻ�
	if ((endInorder - rootInorder) > 0)
	{
		btn->rchild = constructCore(startPreorder + leftlength + 1, endPreorder, rootInorder + 1, endInorder);
		btn->LTag = BiThrNode::PointerTag::Link;
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
	std::cout << "��Tag-����-��Tag" << std::endl << p->LTag << "-" << p->data << "-" << p->RTag << endl;
}

/**
* ���������������б���
* ����ָ��
*/
void inOrderTraverse_Thr(void* (*f)(BiThrNode* p))
{

}


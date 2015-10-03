/****************************************************************************
ʱ�䣺2015��10��3��19:29:38
���ߣ�cutter_point

�ļ���BinarySortTree.h

���ܣ�ʵ�����ǵĲ��ҵĶ���������

****************************************************************************/
#include "BinarySortTree.h"


BinarySortTree::BinarySortTree()
{
}


BinarySortTree::~BinarySortTree()
{
	delete root;
}

/**
 * �ڶ������в�����Ӧ��Ԫ��
 * ����f�ĳ�ʼֵΪnullptr
 * ע����Ϊ�м�Ĳ����趨ȱʡ�ĳ�ֵ��ʱ�򣬺���Ķ�Ҫ�趨
 * t�����ǵĲ������ĸ�
 * pָ���Ԫ�ؽڵ㣨���ҳɹ���������ָ��pָ����ҵ�·�������һ���ڵ㣨����ʧ�ܣ�
 * fָ��T��˫�ף�Ϊ�˺���ݹ�ķ���
 */
bool BinarySortTree::searchBST(int key, BinaryTreeNode *t, BinaryTreeNode *f = nullptr, BinaryTreeNode *p = nullptr)
{
	if (this->root == nullptr)
	{
		//�����Ϊ�յĻ�
		p = f;	//pָ��t��˫��
		return false;
	}//if
	else if (key == t->data)
	{
		//�����ȣ���ô�����ҵ���
		p = t;
		return true;
	}//else if
	else if (key < t->data)
	{
		//������Ҫ�ҵ�ֵС
		return this->searchBST(key, t->lchild, t, p);
	}//else if
	else
	{
		//��ֵ��
		return searchBST(key, t->rchild, t, p);
	}//else

}

/**
 * ��������Ĳ����㷨
 */
bool BinarySortTree::insertBST(int elem)
{
	BinaryTreeNode *p = nullptr;
	BinaryTreeNode *t = root;
	//�ڲ���֮ǰ����Ҫȷ��������û�����Ԫ�أ������ظ�����
	if (!searchBST(elem, t, nullptr, p))
	{
		//�������û�����Ԫ�أ����ǾͲ���
		BinaryTreeNode *s = new BinaryTreeNode();
		s->data = elem;
		//����p��·�������һ��Ԫ��
		if (p != nullptr)
		{
			//pΪ�գ�˵���������û��Ԫ��,��ô���ǾͰ����Ԫ����Ϊ��Ԫ��
			root = s;
		}//if
		else if (elem < p->data)
		{
			//���Ԫ�ر����һ��Ԫ��С
			p->lchild = s;
		}//else if
		else
		{
			p->rchild = s;
		}//else

		return true;
	}
	else
		return false;
}
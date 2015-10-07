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
 *  ɾ�������������еĽڵ�
 */
bool BinarySortTree::deleteBST(BinaryTreeNode *p, int elem)
{
	//�������������������elem����ô����ɾ����
	//�����ж����Ƿ���
	if (p == nullptr)
	{
		return false;
	}//if
	else
	{
		//���Ǳ��������
		if (p->data == elem)
		{
			return delNode(p);
		}//if
		else if (p->data < elem)
		{
			//���������Ҫ�ҵ�ֵС,˵��ֵ���ұ�
			return deleteBST(p->rchild, elem);
		}//else if
		else
		{
			return deleteBST(p->lchild, elem);
		}//else
	}//else if
}

/**
 * ������ɾ������ڵ�
 */
bool BinarySortTree::delNode(BinaryTreeNode *p)
{
	BinaryTreeNode *q;
	if (p->lchild == nullptr)
	{
		//���������Ϊ�յĻ�,��ô����ɾ������ڵ��ʱ��
		//ֻҪ������������ԭ���Ľڵ�Ϳ�����
		q = p; p = p->rchild;
		delete q;	//����
	}//if
	else if (p->rchild == nullptr)
	{
		q = p; p = p->lchild;
		delete q;
	}//else if
	else
	{
		//������Ҷ�����
		q = p; BinaryTreeNode *s = p->lchild;	//s�����ǵȻ�������p�����Ľڵ�
		//����ȷ��s���ұ�Ϊ�գ�ӦΪ���Ǻͽ�����Ŀ����Ŀ��ڵ��������������Ǹ�����Ҳ����Ŀ��ڵ��ֱ��ǰ��
		while (s->rchild != nullptr)
		{
			q = s;
			s = s->rchild;
		}//while
		//����s��p
		p->data = s->data;
		//�ж�q���ǽ����ڵ��ǰ����˫�׽ڵ��ǲ��Ǿ�������Ҫɾ���Ľڵ�
		if (q != p)
		{
			//������ǣ��Ͱ�ǰ���ڵ��˫�׽ڵ���������趨Ϊ������ǰ����������
			q->rchild = s->lchild;
		}//if
		else
		{
			//����ǣ���ô������ǰ���ڵ��������ֱ�Ӹ�����֮��Ľڵ������
			q->lchild = s->lchild;
		}//else
	}//else

	return true;
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
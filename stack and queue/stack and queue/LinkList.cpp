/*
*���ܣ����ʵ�ֵ�������Ĺ���
*�ļ���LinkList.cpp
*ʱ�䣺2015��7��7��20:33:18,2015��7��8��20:01:31,2015��7��9��20:42:11
*���ߣ�cutter_point
*/

#include "LinkList.h"

#include <iostream>

using namespace std;

/*******************************************************Node****************************************************************************/


/*******************************************************LinkList****************************************************************************/
//void insert(Event e);	//������ĩβ���һ��Ԫ��
void LinkList::insert(Event e)
{
	//����һ��Ԫ��,���������ж��������Ƿ���Ԫ��
	bool a;
	if (a = this->listEmpty())		//Ϊtrue������
		this->head = new Node();
	//���ڲ����Ƿ���Ԫ�ض���һ��Ԫ���ˣ��������Ԫ��ʱ�յģ�����Ϊͷ���������ǰ��µ�Ԫ����ӽ�ȥ
	Node *p = this->head;	//��һ���α�ָ��
	Node* val = new Node(e);
	//Ȼ����µ�val�ӵ�Ԫ�ص�ĩβ
	p = this->getTail();
	//����pָ��βԪ�أ����ǰ�Ԫ�ؽӵ�ĩβ
	p->setNext(val); //��val��Ϊβ����Ԫ��
}

//Node* getHead();	//ȡ��ͷָ��
Node* LinkList::getHead()
{
	return this->head;
}

Node* LinkList::getTail()
{
	Node* p = this->head;
	while (p->getNext() != nullptr)
	{
		p = p->getNext(); //ѭ�������һ���ڵ�
	}
	return p;
}

//Node* pop(); //ɾ�����һ���ڵ�
Node* LinkList::pop()
{
	//��һ���α�ָ��
	Node* p = this->getHead();
	Node* q = this->getHead();
	//�����ж��Ƿ���Ԫ�ؿ���ɾ��,������ж���������ͷָ������Ǹ��ǲ���Ϊ�յ�
	if (p->getNext() == nullptr)
	{
		cout << "�¼���Ϊ��" << endl;
		return nullptr;
	}
	//ѭ�������һ���͵����ڶ���
	while (p->getNext() != nullptr)
	{
		q = p;		//�õ���һ���ڵ�
		p = p->getNext();	//ȥ��һ���ڵ�
	}
	//���ĩβ��Ϊ�գ�˵������Ԫ�أ���ô���Ǿ�ɾ�������һ��,���������һ��
	q->setNext(nullptr); //�ɵ����ڶ����趨Ϊ�գ��Ͽ�����
	return p; //���ضϿ�����Ǹ����ݵ�ָ��
}

//bool listEmpty();	//�ж��Ƿ��ǿ�����
bool LinkList::listEmpty()
{
	//�ж��Ƿ�Ϊ�յı�ʶ����ͷָ���βָ����ͬһ���ڵ㣬��ô�ʹ���Ϊ��
	if (this->getHead() == this->getTail())
	{
		//û����һ���ڵ�
		return true;
	}
	return false; //ͷ������һ����Ϊ��
}




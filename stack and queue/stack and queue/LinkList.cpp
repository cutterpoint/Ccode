/*
*功能：这个实现的是链表的功能
*文件：LinkList.cpp
*时间：2015年7月7日20:33:18,2015年7月8日20:01:31,2015年7月9日20:42:11
*作者：cutter_point
*/

#include "LinkList.h"

#include <iostream>

using namespace std;

/*******************************************************Node****************************************************************************/


/*******************************************************LinkList****************************************************************************/
//void insert(Event e);	//给链表末尾添加一个元素
void LinkList::insert(Event e)
{
	//插入一个元素,首先我们判断链表中是否含有元素
	bool a;
	if (a = this->listEmpty())		//为true就是真
		this->head = new Node();
	//现在不管是否含有元素都有一个元素了，但是这个元素时空的，来作为头，接着我们把新的元素添加进去
	Node *p = this->head;	//用一个游标指针
	Node* val = new Node(e);
	//然后把新的val接到元素的末尾
	p = this->getTail();
	//现在p指向尾元素，我们把元素接到末尾
	p->setNext(val); //吧val设为尾部的元素
}

//Node* getHead();	//取得头指针
Node* LinkList::getHead()
{
	return this->head;
}

Node* LinkList::getTail()
{
	Node* p = this->head;
	while (p->getNext() != nullptr)
	{
		p = p->getNext(); //循环到最后一个节点
	}
	return p;
}

//Node* pop(); //删除最后一个节点
Node* LinkList::pop()
{
	//用一个游标指针
	Node* p = this->getHead();
	Node* q = this->getHead();
	//首先判断是否还有元素可以删除,这个的判断条件就是头指针后面那个是不是为空的
	if (p->getNext() == nullptr)
	{
		cout << "事件表为空" << endl;
		return nullptr;
	}
	//循环到最后一个和倒数第二个
	while (p->getNext() != nullptr)
	{
		q = p;		//得到上一个节点
		p = p->getNext();	//去下一个节点
	}
	//如果末尾不为空，说明还有元素，那么我们就删除掉最后一个,并返回最后一个
	q->setNext(nullptr); //吧倒数第二个设定为空，断开连接
	return p; //返回断开后的那个数据的指针
}

//bool listEmpty();	//判断是否是空链表
bool LinkList::listEmpty()
{
	//判断是否为空的标识就是头指针和尾指针是同一个节点，那么就代表为空
	if (this->getHead() == this->getTail())
	{
		//没有下一个节点
		return true;
	}
	return false; //头结点的下一个不为空
}




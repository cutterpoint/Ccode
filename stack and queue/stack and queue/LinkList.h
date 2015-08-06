/*
*功能：这个实现的是链表的功能
*文件：LinkList.h
*时间：2015年7月7日20:33:18,2015年7月8日20:01:31
*作者：cutter_point
*/

#ifndef LINKLIST_H
#define LINKLIST_H

#include "Event.h"
#include <stdio.h>

using namespace std;

//链表的一个节点
class Node
{
	Event event; //创建我们的数据元对象，包含一个事件发生时间和一个事件类型
	Node* next;
public:
	Node() { this->next = nullptr; }
	Node(Event e) { this->event = e; this->next = nullptr; }

	//set和get方法
	void setEvent(Event e) { this->event = e; }
	Event getEvent() { return this->event; }
	void setNext(Node* n) { this->next = n; }
	Node* getNext() { return this->next; }
};

//我们的链表
class LinkList
{
	Node* head;	//头指针
	Node* getTail();	//得到尾部指针
public:
	LinkList(){ this->head = new Node(); }
	void insert(Event e);	//给链表末尾添加一个元素
	Node* pop(); //删除最后一个节点
	bool listEmpty();	//判断是否是空链表
	Node* getHead();	//取得头指针
};

#endif

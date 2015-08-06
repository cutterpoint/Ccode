/*
*���ܣ����ʵ�ֵ�������Ĺ���
*�ļ���LinkList.h
*ʱ�䣺2015��7��7��20:33:18,2015��7��8��20:01:31
*���ߣ�cutter_point
*/

#ifndef LINKLIST_H
#define LINKLIST_H

#include "Event.h"
#include <stdio.h>

using namespace std;

//�����һ���ڵ�
class Node
{
	Event event; //�������ǵ�����Ԫ���󣬰���һ���¼�����ʱ���һ���¼�����
	Node* next;
public:
	Node() { this->next = nullptr; }
	Node(Event e) { this->event = e; this->next = nullptr; }

	//set��get����
	void setEvent(Event e) { this->event = e; }
	Event getEvent() { return this->event; }
	void setNext(Node* n) { this->next = n; }
	Node* getNext() { return this->next; }
};

//���ǵ�����
class LinkList
{
	Node* head;	//ͷָ��
	Node* getTail();	//�õ�β��ָ��
public:
	LinkList(){ this->head = new Node(); }
	void insert(Event e);	//������ĩβ���һ��Ԫ��
	Node* pop(); //ɾ�����һ���ڵ�
	bool listEmpty();	//�ж��Ƿ��ǿ�����
	Node* getHead();	//ȡ��ͷָ��
};

#endif

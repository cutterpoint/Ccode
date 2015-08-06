/*
*���ܣ����ʵ�ֵ��������¼��Ķ���
*�ļ���LinkQueue.h
*ʱ�䣺2015��7��9��17:17:09
*���ߣ�cutter_point
*/

#ifndef LINKQUEUE_H
#define LINKQUEUE_H

class QNode
{
	int arrivalTime;	//ʱ�䵽��ʱ��
	int duration;	//����ҵ������Ҫ��ʱ��
	QNode* next;	//ָ����һ���ڵ�
public:
	QNode()
	{
		this->arrivalTime = 0;
		this->duration = 0;
		this->next = nullptr;
	}

	QNode(QNode* e)
	{
		this->arrivalTime = e->arrivalTime;
		this->duration = e->duration;
		this->next = nullptr;
	}

	//set��get����
	void setArrivalTime(int arrival) { this->arrivalTime = arrival; }
	int getArrivalTime() { return this->arrivalTime; }
	void setDuration(int dur) { this->duration = dur; }
	int getDuration() { return this->duration; }
	void setNext(QNode* n) { this->next = n; }
	QNode* getNext() { return this->next; }
};

class LinkQueue
{
	//QNode* base;	//��ʼ���Ķ�̬����洢�ռ�
	QNode* front;	//���е�ͷ
	QNode* rear;	//���е�β
public:
	LinkQueue(); //��ʼ��
	void enQueue(QNode* e); //��������
	QNode deQueue(); //ɾ��һ������
	bool queueEmpty();	//�ж϶����Ƿ�Ϊ��
	QNode getHead();	//��ȡ���е�ͷԪ��
	int length();
	//set��get����
	void setFront(QNode* qn) { this->front = qn; }
	QNode* getFront() { return this->front; }
	void setRear(QNode* qn) { this->rear = qn; }
	QNode* getRear() { return this->rear; }
};

#endif


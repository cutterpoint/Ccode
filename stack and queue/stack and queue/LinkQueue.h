/*
*功能：这个实现的是我们事件的队列
*文件：LinkQueue.h
*时间：2015年7月9日17:17:09
*作者：cutter_point
*/

#ifndef LINKQUEUE_H
#define LINKQUEUE_H

class QNode
{
	int arrivalTime;	//时间到达时间
	int duration;	//处理业务所需要的时间
	QNode* next;	//指向下一个节点
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

	//set和get方法
	void setArrivalTime(int arrival) { this->arrivalTime = arrival; }
	int getArrivalTime() { return this->arrivalTime; }
	void setDuration(int dur) { this->duration = dur; }
	int getDuration() { return this->duration; }
	void setNext(QNode* n) { this->next = n; }
	QNode* getNext() { return this->next; }
};

class LinkQueue
{
	//QNode* base;	//初始化的动态分配存储空间
	QNode* front;	//队列的头
	QNode* rear;	//队列的尾
public:
	LinkQueue(); //初始化
	void enQueue(QNode* e); //插入数据
	QNode deQueue(); //删除一个数据
	bool queueEmpty();	//判断队列是否为空
	QNode getHead();	//获取队列的头元素
	int length();
	//set和get方法
	void setFront(QNode* qn) { this->front = qn; }
	QNode* getFront() { return this->front; }
	void setRear(QNode* qn) { this->rear = qn; }
	QNode* getRear() { return this->rear; }
};

#endif


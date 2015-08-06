/*
*功能：这个实现的是我们事件的队列
*文件：LinkQueue.h
*时间：2015年7月9日17:17:09,2015年7月10日15:18:58
*作者：cutter_point
*/

#include "LinkQueue.h"

//LinkQueue(); //初始化
LinkQueue::LinkQueue()
{
	//初始化队列的时候，队列是先进先出
	//首先我们创建一个新的空节点
	this->rear = this->front = new QNode();
	this->front->setNext(nullptr);	//初始化的时候只有一个节点，后面的设置为nullptr
}

//得到队列的长度
int LinkQueue::length()
{
	//由于第一个是空的，所以我们判断队列的长度就是尾部和首部的长度
	int length = 0;
	QNode* p = this->front;	//用一个游标当做指针，指向相应的位置
	while (p != this->rear)
	{
		p = p->getNext();
		++length;
	}
	return length;	//返回队列的长度
}

//void enQueue(QNode* e); //插入数据
void LinkQueue::enQueue(QNode* e)
{
	//吧原始e插入到队列中，由于我们的是链表，不用考虑队列会不会满的问题，如果是线性表，我们还要考虑队列是否满的问题，因为初始化的时候，线性表示一次性申请完全的
	this->rear->setNext(e);
	//然后重置尾节点
	this->rear = this->rear->getNext();
}

//QNode deQueue(); //删除一个数据,删除的是队首元素
QNode LinkQueue::deQueue()
{
	//这个就是出队列的动作
	QNode e;
	//设置两个游标
	QNode* p,* q;
	
	//我们首先得判断一下是不是只有一个节点，如果是只有一个有效节点，那么就得更新rear
	if (this->getFront()->getNext() == this->getRear())
	{
		this->setRear(this->getFront());	//设置到头结点上
	}
	//我们的操作就是把头后面的那个节点拿出来，抛出来
	p = this->getFront();
	q = p->getNext();
	//断裂头和第一个元素的指针，吧指针指向后面一个节点
	p->setNext(q->getNext());
	q->setNext(nullptr);
	//吧q这个节点的值赋值给e然后返回，并回收q的内存
	e.setArrivalTime(q->getArrivalTime());
	e.setDuration(q->getDuration());
	e.setNext(nullptr);
	delete q;
	return e;
}

//bool queueEmpty();	//判断队列是否为空
bool LinkQueue::queueEmpty()
{
	//判断是不是为空的理由就是头和尾是不是指向一个地方
	if (this->getFront() == this->getRear())
	{
		return true;
	}
	else
	{
		return false;
	}
}

//QNode getHead();	//获取队列的第一个元素,这里只是返回第一个元素的拷贝元素
QNode LinkQueue::getHead()
{
	QNode e;
	e.setArrivalTime(this->getFront()->getNext()->getArrivalTime());
	e.setDuration(this->getFront()->getNext()->getDuration());
	e.setNext(nullptr);
	return e;
}



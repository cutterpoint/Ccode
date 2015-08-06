/*
*���ܣ����ʵ�ֵ��������¼��Ķ���
*�ļ���LinkQueue.h
*ʱ�䣺2015��7��9��17:17:09,2015��7��10��15:18:58
*���ߣ�cutter_point
*/

#include "LinkQueue.h"

//LinkQueue(); //��ʼ��
LinkQueue::LinkQueue()
{
	//��ʼ�����е�ʱ�򣬶������Ƚ��ȳ�
	//�������Ǵ���һ���µĿսڵ�
	this->rear = this->front = new QNode();
	this->front->setNext(nullptr);	//��ʼ����ʱ��ֻ��һ���ڵ㣬���������Ϊnullptr
}

//�õ����еĳ���
int LinkQueue::length()
{
	//���ڵ�һ���ǿյģ����������ж϶��еĳ��Ⱦ���β�����ײ��ĳ���
	int length = 0;
	QNode* p = this->front;	//��һ���α굱��ָ�룬ָ����Ӧ��λ��
	while (p != this->rear)
	{
		p = p->getNext();
		++length;
	}
	return length;	//���ض��еĳ���
}

//void enQueue(QNode* e); //��������
void LinkQueue::enQueue(QNode* e)
{
	//��ԭʼe���뵽�����У��������ǵ����������ÿ��Ƕ��л᲻���������⣬��������Ա����ǻ�Ҫ���Ƕ����Ƿ��������⣬��Ϊ��ʼ����ʱ�����Ա�ʾһ����������ȫ��
	this->rear->setNext(e);
	//Ȼ������β�ڵ�
	this->rear = this->rear->getNext();
}

//QNode deQueue(); //ɾ��һ������,ɾ�����Ƕ���Ԫ��
QNode LinkQueue::deQueue()
{
	//������ǳ����еĶ���
	QNode e;
	//���������α�
	QNode* p,* q;
	
	//�������ȵ��ж�һ���ǲ���ֻ��һ���ڵ㣬�����ֻ��һ����Ч�ڵ㣬��ô�͵ø���rear
	if (this->getFront()->getNext() == this->getRear())
	{
		this->setRear(this->getFront());	//���õ�ͷ�����
	}
	//���ǵĲ������ǰ�ͷ������Ǹ��ڵ��ó������׳���
	p = this->getFront();
	q = p->getNext();
	//����ͷ�͵�һ��Ԫ�ص�ָ�룬��ָ��ָ�����һ���ڵ�
	p->setNext(q->getNext());
	q->setNext(nullptr);
	//��q����ڵ��ֵ��ֵ��eȻ�󷵻أ�������q���ڴ�
	e.setArrivalTime(q->getArrivalTime());
	e.setDuration(q->getDuration());
	e.setNext(nullptr);
	delete q;
	return e;
}

//bool queueEmpty();	//�ж϶����Ƿ�Ϊ��
bool LinkQueue::queueEmpty()
{
	//�ж��ǲ���Ϊ�յ����ɾ���ͷ��β�ǲ���ָ��һ���ط�
	if (this->getFront() == this->getRear())
	{
		return true;
	}
	else
	{
		return false;
	}
}

//QNode getHead();	//��ȡ���еĵ�һ��Ԫ��,����ֻ�Ƿ��ص�һ��Ԫ�صĿ���Ԫ��
QNode LinkQueue::getHead()
{
	QNode e;
	e.setArrivalTime(this->getFront()->getNext()->getArrivalTime());
	e.setDuration(this->getFront()->getNext()->getDuration());
	e.setNext(nullptr);
	return e;
}



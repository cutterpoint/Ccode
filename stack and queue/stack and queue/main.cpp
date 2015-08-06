/*
*功能：假设一个银行有4个窗口对外接待客户。由于每个窗口在某一时刻只能接待一个客户，在客户众多的时候需要排队，对于刚进入银行的客户，如果某个窗口正空闲，
则可上前办理业务，如果所有窗口都不空闲则排在人数最少的窗口。
现在要求模拟银行的某一时间段内的4个窗口的客户排队情况。这里客户到达的时刻和办理业务的时间都是随机的。
**************************************************************************
****这里没有用到线程，其实更好的办法是使用线程，一个线程用来不断产生  ****
****事件（客户的到达）,一个线程不断的处理事件，客户的离开，只要银行不 ****
****关门，当事件表为空的时候我们就wait()一个线程，当队列中还有客户的  ****
****时候就吧线程notify，知道银行关门我们就interrupt线程，结束退出     ****
**************************************************************************
*文件：queue.cpp
*时间：2015年7月7日20:33:18,2015年7月8日20:01:31,2015年7月9日20:02:20,2015年7月10日16:45:52,2015年7月12日15:16:41
*作者：cutter_point
*/

#include "Event.h"
#include "LinkList.h"
#include "LinkQueue.h"

#include <iostream>
#include <ctime>

using namespace std;

const static int COUNTER = 5;	//一共4个窗口
const static int MAX_TIME = 30;	//这个是最大的事务处理时间
const static int INTERVAL = 5;	//每五分钟内出现一个客户

LinkList ev;	//事件表
Event en;
LinkQueue* q[COUNTER];		//这个设定为指针数组，数组里面的每个元素是一个指向LinkQueue的指针
QNode customer;
int TotalTime, CustomerNum, closeTime = 50;

void open_for_day()
{
	cout << "************************************************************************" << endl;
	cout << "*****                         银行开门                             *****" << endl;
	cout << "*****                         银行开门                             *****" << endl;
	cout << "************************************************************************" << endl;
	//初始化所有的数据
	TotalTime = 0; CustomerNum = 0;
	en.setOccurTime(0); en.setNType(0);
	//初始化所有队列
	for (int i = 1; i < COUNTER; ++i)
	{
		q[i] = new LinkQueue();
	}
}//open_for_day()

//求得最短的队列
int min_queue(LinkQueue* q[COUNTER])
{
	int max = 0, usei = 1;
	for (int i = 1; i < COUNTER; ++i)
	{
		//循环遍历所有的队列选出最大的那个队列
		int testmax = q[i]->length();
		if (testmax > max)
		{
			max = testmax;
			usei = i;
		}
	}
	//循环完毕之后max是所有队列中最大的那个
	return usei;
}

void customer_arrived()
{
	cout << "======================一位客户到达======================" << endl;
	//处理客户到达事件，en.NType=0
	QNode *qe = new QNode();	//客户到达时间，处理业务所需要的时间，指向下一个对象
	int durtime, intertime;	//一个是处理业务所需要的时间，一个是下一个客户到达的所需时间

	++CustomerNum;	//人数++

	//参数两个随机数，代表处理业务需要的时间，下一个客户到达的时间
	durtime = rand() % (MAX_TIME + 1);	//这个额是[0 ~ MAX_TIME(30)]
	intertime = rand() % (INTERVAL + 1);	//这个是下一个客户进入银行要等待的时间[0~INTERVAL(5)]

	//如果银行没有关门，我们要产生下一个事件到达
	int t = en.getOccurTime() + intertime;
	if (t < closeTime)
	{
		//插入事件表下一个事件
		Event ei;
		ei.setOccurTime(t);
		ei.setNType(0);
		ev.insert(ei);
	}

	int i = min_queue(q);	//求得最短的队列，注意我们有1到4队列，没有0队列
	//吧事件插入到最短的队列中
	//首先我们的事件发生时间(事件到达时间)和执行时间
	qe->setArrivalTime(en.getOccurTime());
	qe->setDuration(durtime);	//时间的执行时间
	q[i]->enQueue(qe);	//吧qe插入到链表中

	//判断我们插入的队列是不是长度是1，如果是代表在插入之前这个窗口是空的，这个的作用
	//客户离开事件，是要首先计算该客户在银行逗留的时间，然后从队列中删除该客户之后查看队列是否为空，若不为空则设定一个新的对头客户离开事件
	en.setOccurTime(en.getOccurTime() + durtime);	//设置新的时间到达事件
	en.setNType(i);	//0代表新的客户到达，1是1号窗口客户离开，2是2号窗口客户离开，3是3号窗口客户离开，4是。。。,这里是客户到达事件，所以是0
	if (q[i]->length() == 1)
	{
		//吧第i个队列的离开事件插入事件表，等会用来计算窗口的客户总时间
		ev.insert(en);
	}

}//customer_arrived()

//处理客户离开事件，是要首先计算该客户在银行逗留的时间，然后从队列中删除该客户之后查看队列是否为空，若不为空则设定一个新的对头客户离开事件
void customer_departure()
{
	cout << "======================一位客户离开======================" << endl;
	//处理客户离开事件，就是Ntype > 0
	int i = en.getNType();	//得到事件的类型
	q[i]->deQueue();	//吧排头删除,表示排头客户离开
	TotalTime += en.getOccurTime() - customer.getArrivalTime();	//这个是客户逗留事件，不包含处理业务的时间，这个计算的也就是客户等待时间
	//如果走了这个客户，队列不是空，则设定一个新的排头客户
	if (q[i]->length() != 0)
	{
		Event e;
		customer = q[i]->getHead(); //得到排头的客户
		e.setOccurTime(en.getOccurTime() + customer.getDuration()); //客户开始办理业务时间+客户使用时间，也就是到了客户离开时间
		e.setNType(i);	//那个窗口的
		ev.insert(e);
	}
}

//这个函数用来产生一系列事件,我们首先产生20个事件
void create_event()
{
	for (int i = 1; i < 2; ++i)
	{
		customer_arrived();
	}
}

void bank_smiulation(int closeTime)
{
	open_for_day();	//银行开始业务
	create_event();	//产生事件
	while (!ev.listEmpty())	//只要事件表还没空
	{
		//Node* p = ev.getHead();	//从事件链表中弹出事件
		Node* p = ev.pop();
		en = p->getEvent();	//取出时间
		if (en.getNType() == 0)
		{
			//客户到达事件
			customer_arrived();
		}
		else
		{
			//客户离开
			customer_departure();
		}
	}//while

	//计算并输出平均逗留时间
	cout << "平均逗留时间是：" << (float)TotalTime/CustomerNum << endl;
}

int main()
{
	bank_smiulation(closeTime);
	//ev.getHead()->getEvent().getOccurTime();
	//cout << "hello world" << ev.getHead()->getEvent().getOccurTime()<<endl;

	return 0;
}

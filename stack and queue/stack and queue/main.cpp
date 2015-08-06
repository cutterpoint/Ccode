/*
*���ܣ�����һ��������4�����ڶ���Ӵ��ͻ�������ÿ��������ĳһʱ��ֻ�ܽӴ�һ���ͻ����ڿͻ��ڶ��ʱ����Ҫ�Ŷӣ����ڸս������еĿͻ������ĳ�����������У�
�����ǰ����ҵ��������д��ڶ��������������������ٵĴ��ڡ�
����Ҫ��ģ�����е�ĳһʱ����ڵ�4�����ڵĿͻ��Ŷ����������ͻ������ʱ�̺Ͱ���ҵ���ʱ�䶼������ġ�
**************************************************************************
****����û���õ��̣߳���ʵ���õİ취��ʹ���̣߳�һ���߳��������ϲ���  ****
****�¼����ͻ��ĵ��,һ���̲߳��ϵĴ����¼����ͻ����뿪��ֻҪ���в� ****
****���ţ����¼���Ϊ�յ�ʱ�����Ǿ�wait()һ���̣߳��������л��пͻ���  ****
****ʱ��Ͱ��߳�notify��֪�����й������Ǿ�interrupt�̣߳������˳�     ****
**************************************************************************
*�ļ���queue.cpp
*ʱ�䣺2015��7��7��20:33:18,2015��7��8��20:01:31,2015��7��9��20:02:20,2015��7��10��16:45:52,2015��7��12��15:16:41
*���ߣ�cutter_point
*/

#include "Event.h"
#include "LinkList.h"
#include "LinkQueue.h"

#include <iostream>
#include <ctime>

using namespace std;

const static int COUNTER = 5;	//һ��4������
const static int MAX_TIME = 30;	//���������������ʱ��
const static int INTERVAL = 5;	//ÿ������ڳ���һ���ͻ�

LinkList ev;	//�¼���
Event en;
LinkQueue* q[COUNTER];		//����趨Ϊָ�����飬���������ÿ��Ԫ����һ��ָ��LinkQueue��ָ��
QNode customer;
int TotalTime, CustomerNum, closeTime = 50;

void open_for_day()
{
	cout << "************************************************************************" << endl;
	cout << "*****                         ���п���                             *****" << endl;
	cout << "*****                         ���п���                             *****" << endl;
	cout << "************************************************************************" << endl;
	//��ʼ�����е�����
	TotalTime = 0; CustomerNum = 0;
	en.setOccurTime(0); en.setNType(0);
	//��ʼ�����ж���
	for (int i = 1; i < COUNTER; ++i)
	{
		q[i] = new LinkQueue();
	}
}//open_for_day()

//�����̵Ķ���
int min_queue(LinkQueue* q[COUNTER])
{
	int max = 0, usei = 1;
	for (int i = 1; i < COUNTER; ++i)
	{
		//ѭ���������еĶ���ѡ�������Ǹ�����
		int testmax = q[i]->length();
		if (testmax > max)
		{
			max = testmax;
			usei = i;
		}
	}
	//ѭ�����֮��max�����ж����������Ǹ�
	return usei;
}

void customer_arrived()
{
	cout << "======================һλ�ͻ�����======================" << endl;
	//����ͻ������¼���en.NType=0
	QNode *qe = new QNode();	//�ͻ�����ʱ�䣬����ҵ������Ҫ��ʱ�䣬ָ����һ������
	int durtime, intertime;	//һ���Ǵ���ҵ������Ҫ��ʱ�䣬һ������һ���ͻ����������ʱ��

	++CustomerNum;	//����++

	//���������������������ҵ����Ҫ��ʱ�䣬��һ���ͻ������ʱ��
	durtime = rand() % (MAX_TIME + 1);	//�������[0 ~ MAX_TIME(30)]
	intertime = rand() % (INTERVAL + 1);	//�������һ���ͻ���������Ҫ�ȴ���ʱ��[0~INTERVAL(5)]

	//�������û�й��ţ�����Ҫ������һ���¼�����
	int t = en.getOccurTime() + intertime;
	if (t < closeTime)
	{
		//�����¼�����һ���¼�
		Event ei;
		ei.setOccurTime(t);
		ei.setNType(0);
		ev.insert(ei);
	}

	int i = min_queue(q);	//�����̵Ķ��У�ע��������1��4���У�û��0����
	//���¼����뵽��̵Ķ�����
	//�������ǵ��¼�����ʱ��(�¼�����ʱ��)��ִ��ʱ��
	qe->setArrivalTime(en.getOccurTime());
	qe->setDuration(durtime);	//ʱ���ִ��ʱ��
	q[i]->enQueue(qe);	//��qe���뵽������

	//�ж����ǲ���Ķ����ǲ��ǳ�����1������Ǵ����ڲ���֮ǰ��������ǿյģ����������
	//�ͻ��뿪�¼�����Ҫ���ȼ���ÿͻ������ж�����ʱ�䣬Ȼ��Ӷ�����ɾ���ÿͻ�֮��鿴�����Ƿ�Ϊ�գ�����Ϊ�����趨һ���µĶ�ͷ�ͻ��뿪�¼�
	en.setOccurTime(en.getOccurTime() + durtime);	//�����µ�ʱ�䵽���¼�
	en.setNType(i);	//0�����µĿͻ����1��1�Ŵ��ڿͻ��뿪��2��2�Ŵ��ڿͻ��뿪��3��3�Ŵ��ڿͻ��뿪��4�ǡ�����,�����ǿͻ������¼���������0
	if (q[i]->length() == 1)
	{
		//�ɵ�i�����е��뿪�¼������¼����Ȼ��������㴰�ڵĿͻ���ʱ��
		ev.insert(en);
	}

}//customer_arrived()

//����ͻ��뿪�¼�����Ҫ���ȼ���ÿͻ������ж�����ʱ�䣬Ȼ��Ӷ�����ɾ���ÿͻ�֮��鿴�����Ƿ�Ϊ�գ�����Ϊ�����趨һ���µĶ�ͷ�ͻ��뿪�¼�
void customer_departure()
{
	cout << "======================һλ�ͻ��뿪======================" << endl;
	//����ͻ��뿪�¼�������Ntype > 0
	int i = en.getNType();	//�õ��¼�������
	q[i]->deQueue();	//����ͷɾ��,��ʾ��ͷ�ͻ��뿪
	TotalTime += en.getOccurTime() - customer.getArrivalTime();	//����ǿͻ������¼�������������ҵ���ʱ�䣬��������Ҳ���ǿͻ��ȴ�ʱ��
	//�����������ͻ������в��ǿգ����趨һ���µ���ͷ�ͻ�
	if (q[i]->length() != 0)
	{
		Event e;
		customer = q[i]->getHead(); //�õ���ͷ�Ŀͻ�
		e.setOccurTime(en.getOccurTime() + customer.getDuration()); //�ͻ���ʼ����ҵ��ʱ��+�ͻ�ʹ��ʱ�䣬Ҳ���ǵ��˿ͻ��뿪ʱ��
		e.setNType(i);	//�Ǹ����ڵ�
		ev.insert(e);
	}
}

//���������������һϵ���¼�,�������Ȳ���20���¼�
void create_event()
{
	for (int i = 1; i < 2; ++i)
	{
		customer_arrived();
	}
}

void bank_smiulation(int closeTime)
{
	open_for_day();	//���п�ʼҵ��
	create_event();	//�����¼�
	while (!ev.listEmpty())	//ֻҪ�¼���û��
	{
		//Node* p = ev.getHead();	//���¼������е����¼�
		Node* p = ev.pop();
		en = p->getEvent();	//ȡ��ʱ��
		if (en.getNType() == 0)
		{
			//�ͻ������¼�
			customer_arrived();
		}
		else
		{
			//�ͻ��뿪
			customer_departure();
		}
	}//while

	//���㲢���ƽ������ʱ��
	cout << "ƽ������ʱ���ǣ�" << (float)TotalTime/CustomerNum << endl;
}

int main()
{
	bank_smiulation(closeTime);
	//ev.getHead()->getEvent().getOccurTime();
	//cout << "hello world" << ev.getHead()->getEvent().getOccurTime()<<endl;

	return 0;
}

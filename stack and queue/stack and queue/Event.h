/*
*���ܣ����ʵ�ֵ��������¼������ݵ�Ԫ�ڵ�
*�ļ���Event.h
*ʱ�䣺2015��7��8��20:55:32
*���ߣ�cutter_point
*/

#ifndef EVENT_H
#define EVENT_H

class Event
{
	int OccurTime;	//�¼�������ʱ��
	int NType;		//�¼����ͣ�0��ʾ�����¼���1��4��ʾ�ĸ����ڵ��뿪�¼�
public:
	Event() //��ʼ�������ǰ��¼��������¼����¼����Ͷ�������Ϊ0
	{
		this->OccurTime = 0;
		this->NType = 0;
	}
	Event(int Occur, int type)
	{
		this->OccurTime = Occur;
		this->NType = type;
	}

	//��д=�������������������
	/*
	Event& operator=(const Event& event)
	{
		if (event == NULL)
		{
		}
	}
	*/

	//set��get����
	void setOccurTime(int OccurTime) {	this->OccurTime = OccurTime; }
	int getOccurTime() { return this->OccurTime; }
	void setNType(int type) { this->NType = type; }
	int getNType() { return this->NType; }

};

#endif
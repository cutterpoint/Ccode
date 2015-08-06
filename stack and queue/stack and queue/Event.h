/*
*功能：这个实现的是我们事件的数据单元节点
*文件：Event.h
*时间：2015年7月8日20:55:32
*作者：cutter_point
*/

#ifndef EVENT_H
#define EVENT_H

class Event
{
	int OccurTime;	//事件发生的时刻
	int NType;		//事件类型，0表示到达事件，1到4表示四个窗口的离开事件
public:
	Event() //初始化，我们把事件发生的事件和事件类型都首先视为0
	{
		this->OccurTime = 0;
		this->NType = 0;
	}
	Event(int Occur, int type)
	{
		this->OccurTime = Occur;
		this->NType = type;
	}

	//重写=操作符，运算符的重载
	/*
	Event& operator=(const Event& event)
	{
		if (event == NULL)
		{
		}
	}
	*/

	//set和get方法
	void setOccurTime(int OccurTime) {	this->OccurTime = OccurTime; }
	int getOccurTime() { return this->OccurTime; }
	void setNType(int type) { this->NType = type; }
	int getNType() { return this->NType; }

};

#endif
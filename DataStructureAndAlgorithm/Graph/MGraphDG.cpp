/****************************************************************************
时间：2015年9月6日15:15:01
作者：cutter_point

文件：MGraphDG.cpp

功能：实现我们的无向图的构建，采用十字链表存储表示

****************************************************************************/

#include "stdafx.h"
#include "MGraphDG.h"

#include <sstream>

/////////////////////////////////////////////////////////////////////////////
////////////////////////////我们的顶点节点类的声明///////////////////////////////
VexNode::~VexNode()
{
	delete firstin;
	delete firstout;
}


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////我们的弧节点类的声明////////////////////////////////
ArcBox::~ArcBox()
{
	delete hlink, tlink;
}


/////////////////////////////////////////////////////////////////////////////
///////////////////我们的十字链表存储表示,我们的有向图类的声明///////////////////////
MGraphDG::MGraphDG()
{

}


MGraphDG::~MGraphDG()
{
	delete[] xlist;
}

/**
 *  读取文件
 */
void MGraphDG::readFile(std::string filename)
{
	std::ifstream in(filename);
	std::string line;	//一行数据
	int num = 0;	//我们的行数

	if (in.is_open())
	{
		while (std::getline(in, line, '\n'))
		{
			if (num == 0)
			{
				//初始化，顶点个数和弧的个数
				this->intiVAnum(line);
				++num;
			}//if
			else if (num == 1)
			{
				//初始化，我们的顶点向量数组
				this->initXlist(line);
				++num;
			}//else if
			else
			{
				//初始化我们的十字链表
				this->initLink(line);
				++num;
			}
		}//while
		//关闭文件流
		in.clear();
		in.close();
	}
}

/**
 *  初始化我们的数据成员，顶点数和弧数
 * 格式：4 7
 */
void MGraphDG::intiVAnum(std::string line)
{
	std::stringstream sstr(line);	//用这个类可以很好地处理string类型
	std::string num1, num2;
	sstr >> num1 >> num2;	//获取两个数字的字符串
	this->vexnum = atoi(num1.c_str());
	this->arcnum = atoi(num2.c_str());
}

/**
 *  初始化我们的顶点数组
 *  格式：  v1 v2 v3 v4
 */
void MGraphDG::initXlist(std::string line)
{
	std::stringstream ss(line);	//我们把向量输入到我们的数组中
	for (int i = 0; i < vexnum; ++i)
	{
		ss >> xlist[i].nodeName;
	}//for
}

/**
 *  初始化我们各个弧和十字链表
 *  v1:v2 v1:v3 v3:v1 v3:v4 v4:v1 v4:v2 v4:v3
 */
void MGraphDG::initLink(std::string line)
{
	std::stringstream ss(line);	//字符流
	for (int k = 0; k < arcnum; ++k)
	{
		std::string temp, name1, name2;
		ss >> temp;	//得到第一个空格之前的数据
		name1 = temp.substr(0, 2);
		name2 = temp.substr(3, 2);
		//根据向量名字得到我们的向量的位置   i----->j
		int i = this->locateVex(name1);
		int j = this->locateVex(name2);
		//创建我们的弧节点，并初始化相应的数据
		ArcBox *p = new ArcBox();
		//弧尾，弧头
		p->tailvex = i; p->headvex = j;
		//我们这个弧对应的节点的，相同的弧头和弧尾的节点，我们用头插法，连接到一起
		p->hlink = xlist[j].firstin;  p->tlink = xlist[i].firstout;
		p->info = name1 + "==>" + name2;	//节点信息
		//我们把这个弧插入到弧尾的节点之后，把前面的弧连接到这个弧的末尾
		xlist[j].firstin = xlist[i].firstout = p;
	}
}

/**
 *  得到我们的向量在数组中的位置
 */
int MGraphDG::locateVex(std::string name)
{
	if (name == "")
		return -1;
	for (int i = 0; i < vexnum; ++i)
	{
		//寻找向量所在的位置
		if (xlist[i].nodeName == name)
		{
			return i;
		}//if
	}//for
}


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
				++num;
			}//else if
			else
			{
				//初始化我们的十字链表

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
*/
void initXlist(std::string line);

/**
*  初始化我们各个弧和十字链表
*/
void initLink(std::string line);

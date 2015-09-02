/****************************************************************************
时间：2015年8月31日17:23:44
作者：cutter_point

文件：MGraph.cpp

功能：实现我们的各种图的操作

****************************************************************************/

#include "stdafx.h"
#include "MGraphUDN.h"


MGraphUDN::MGraphUDN()
{
}


MGraphUDN::~MGraphUDN()
{
}

//我们用一个函数来确定我们这个顶点的位置
int MGraphUDN::locateVex(char u)
{
	//确定我们的u是顶点向量的第几个
	int i = 0;
	for (; i < vexnum; ++i)
	{
		//比较和这个字符是否一样,当相等的时候返回0，1>2返回正数，否则返回负数
		if (strcmp(&vexs[i], &u) == 0)
		{
			return i;
		}//if
	}//for
	//如果没有匹配到相应的字符
	return -1;
}

//从文件中读取数据初始化我们的成员变量
//第一行的意识是   顶点数：弧度数 例如：（6:10)表示有6个顶点，10个弧
//第二行的意识是   顶点向量	例如：（v1 : v2 : v3 : v4 : v5 : v6) 6个顶点
//第三行的意识是   我们每条弧的弧尾，弧头, 权值 例如：（v1 : v2 : 5 v1 : v4 : 7 .....)
void MGraphUDN::initData(std::string filename)
{
	const int SIZE = 512;	//每行读取100个字符，或者遇到'\0'
	std::ifstream datasource(filename);
	int i = 1; //用来表示行数
	char buf[SIZE];
	//循环读取每一行
	while (datasource.get(buf, SIZE))
	{
		//首先这一行不能是空的
		if (buf[0] != ' ')
		{
			if (i == 1)
			{
				//第一行是 顶点数：弧度数 例如：（6:10)表示有6个顶点，10个弧
				//int vexnum   顶点个数  int arcnum  弧的个数，也就是我们图的边数
				//我们是用'：'分割的,我们借助库函数atoi
				//我们先得到我们的字符的真实长度
				int length = 0;
				while (buf[length] != '\0')
				{
					++length;
				}//while
				int splitindex = getIndexOfFlag(&buf[0], &buf[length - 1], ':');
				//前面的是vecnum,后面的是arcnum
				char *vecc = new char[splitindex];
				for (int i = 0; i < splitindex; ++i)
					vecc[i] = buf[i];
				vexnum = atoi(vecc);
				char *arcc = new char[length - splitindex - 1];
				for (int i = 0; i < length - splitindex - 1; ++i)
					arcc[i] = buf[i + splitindex + 1];
				arcnum = atoi(arcc);
				++i;
			}//if
			else if (i == 2)
			{
				//第二行是我们的顶点向量，我们保存到char vexs[MAX_VERTEX_NUM]中
				int 
				++i;
			}//else if
			else if (i == 3)
			{
				i = 1;
			}//else if
		}
		else
			continue;	//下一行
	}//while
}

//得到我们：分割的位置
int MGraphUDN::getIndexOfFlag(char *begin, char *end, char flag)
{
	//从begin到end中第一个：出现的位置
	char *p = begin;
	int index = -1;
	while (p != end + 1)
	{
		++index;
		if (*p == flag)
		{
			//字符得到匹配
			break;
		}//if
		++p;
	}//while

	return index;
}

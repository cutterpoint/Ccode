/****************************************************************************
时间：2015年8月31日17:23:44
作者：cutter_point

文件：MGraph.h

功能：实现我们的各种图的操作

****************************************************************************/

#ifndef _MGRAPH_H_
#define _MGRAPH_H_

#include <fstream>
#include <string>
#include <iostream>

class MGraph
{
public:
	static const int MAX_VERTEX_NUM = 26;	//我们图的最多顶点个数
	MGraph();
	~MGraph();

private:
	char vexs[MAX_VERTEX_NUM];	//存放顶点
	int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//存放矩阵数组
	int vexnum;	//顶点个数
	int arcnum;		//弧的个数，也就是我们图的边数
};

#endif //_MGRAPH_H_
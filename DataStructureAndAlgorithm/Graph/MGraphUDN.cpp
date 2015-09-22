/****************************************************************************
时间：2015年8月31日17:23:44
作者：cutter_point

文件：MGraph.cpp

功能：实现我们的各种图的操作

****************************************************************************/

#include "stdafx.h"
#include "MGraphUDN.h"
#include <iostream>


MGraphUDN::MGraphUDN()
{
}


MGraphUDN::~MGraphUDN()
{
}

MGraphUDN::MGraphUDN(std::string filename)
{
	this->filename = filename;
}

//我们用一个函数来确定我们这个顶点的位置
int MGraphUDN::locateVex(std::string u)
{
	//确定我们的u是顶点向量的第几个
	int i = 0;
	for (; i < vexnum; ++i)
	{
		//比较和这个字符是否一样,当相等的时候返回0，1>2返回正数，否则返回负数
		if (vexs[i] == u)
		{
			return i;
		}//if
	}//for
	//如果没有匹配到相应的字符
	return -1;
}

void MGraphUDN::createUDN()
{
	this->initData(filename);
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
	while (datasource.getline(buf, SIZE))
	{
		//首先这一行不能是空的
		if (buf[0] != ' ')
		{
			//我们先得到我们的字符的真实长度
			int length = 0;
			while (buf[length] != '\0')
			{
				++length;
			}//while
			if (i == 1)
			{
				//第一行是 顶点数：弧度数 例如：（6:10)表示有6个顶点，10个弧
				//int vexnum   顶点个数  int arcnum  弧的个数，也就是我们图的边数
				//我们是用'：'分割的,我们借助库函数atoi				
				int splitindex = getIndexOfFlag(&buf[0], &buf[length - 1], ':');
				//调用函数进行初始化
				this->initNum(buf, splitindex, length);
				++i;
			}//if
			else if (i == 2)
			{
				//第二行是我们的顶点向量，我们保存到string vexs[MAX_VERTEX_NUM]中
				//我们循环遍历，碰到一个：，我们就取一个，最后再取出来一个
				char flag = ':';	//我们分隔的标准
				this->initVexs(buf, flag, length);
				++i;
			}//else if
			else if (i == 3)
			{
				//第三行  我们每条弧的弧尾，弧头,权值 例如：（v1:v2:5 v1:v4:7 .....)
				//这个每条数据是用空格分开的， 我们用这个数据来初始化，我们的无向网
				this->initvvw(buf, length);
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

//初始化 顶点， 弧 的数量，也就是int vexnum  int arcnum
void MGraphUDN::initNum(char *buf, int splitindex, int length)
{
	//前面的是vecnum,后面的是arcnum
	char *vecc = new char[splitindex];
	for (int i = 0; i < splitindex; ++i)
		vecc[i] = buf[i];
	vexnum = atoi(vecc);
	char *arcc = new char[length - splitindex - 1];
	for (int i = 0; i < length - splitindex - 1; ++i)
		arcc[i] = buf[i + splitindex + 1];
	arcnum = atoi(arcc);
}

//初始化我们的string vexs[MAX_VERTEX_NUM]，也就是初始化我们的顶点向量
//v1:v2:v3:v4:v5:v6
void MGraphUDN::initVexs(char *buf, char flag, int length)
{
	int k = 0;	//用来计数是第几个顶点
	for (int j1 = 0, j2 = 0; j1 <= length; ++j1)
	{
		if (buf[j1] == flag || j1 == length)
		{
			std::string s(buf, j2, j1 - j2); //从buf的下标是j2的字符开始，拷贝j1-j2个字符  
			vexs[k++] = s;
			j2 = j1 + 1;
		}//if
	}//for
}

//初始化我们的邻接矩阵
//v1:v2:5 v1:v4:7 v2:v3:4 v3:v1:8 v3:v6:9 v4:v3:5 v4:v6:6 v5:v4:5 v6:v1:3 v6:v5:1
void MGraphUDN::initvvw(char *buf, int length)
{
	if (buf == nullptr)
		return;
	//先把矩阵全部初始化为无限大
	for (int i = 0; i < vexnum; ++i)
	{
		for (int j = 0; j < vexnum; ++j)
		{
			arcs[i][j] = MAX_MAXTRIX_NUM;
		}//for
	}//for
	for (int i1 = 0, i2 = 0; i1 <= length; ++i1)
	{
		if (buf[i1] == ' ' || i1 == length)
		{
			//一个分割v1:v2:5,
			std::string tempS(buf, i2, i1 - i2);
			i2 = i1 + 1;
			//分别代表弧尾，弧头，权值
			std::string v1, v2;
			int weight;
			v1 = tempS.substr(0, 2);
			v2 = tempS.substr(3, 2);
			weight = tempS[6] - '0';
			this->initMatrix(v1, v2, weight);
		}//if
	}//for
}

//初始化邻接矩阵的一个数据
void MGraphUDN::initMatrix(std::string v1, std::string v2, int weight)
{
	//找到邻接矩阵以v1位弧尾，v2为弧头的位置
	int i = this->locateVex(v1);
	int j = this->locateVex(v2);
	this->arcs[i][j] = this->arcs[j][i] = weight;
}

/**
 * 输出矩阵
 */
void MGraphUDN::printMaxtrix()
{
	for (int i = 0; i < vexnum; ++i)
	{
		for (int j = 0; j < vexnum; ++j)
		{
			std::cout << arcs[i][j] << "\t";
		}//for
		std::cout << std::endl;
	}//for
}

/**
 *  在求最小生成树的时候，这个用来
 *  求出closedge中最小的那个节点位置
 */
int MGraphUDN::minimum()
{
	//当我们的closedge中的lowcost为0的时候，表示已经划入到集合中
	//也就是说不用进行搜索查询了
	int min = 0;
	int result = -1;
	for (int i = 0; i < vexnum; ++i)
	{
		if (closedge[i].lowcost > 0)
		{
			//还没有被并到集合中的话
			if (min == 0)
			{
				//如果是第一个的话
				min = closedge[i].lowcost;
				result = i;
			}//if
			else
			{
				//比较大小
				min = closedge[i].lowcost < min ? closedge[i].lowcost, result = i : min;
			}//else
		}//if
	}//for

	return result;
}

/**
 *  最小生成树
 */
void MGraphUDN::miniSpanTree_PRIM(std::string name)
{
	if (name == "")
		return;
	int k = locateVex(name);	//得到这个对象所在的位置
	//初始化我们的最小生成树的存放最小路径的数组
	for (int i = 0; i < vexnum; ++i)
	{
		closedge[i].lowcost = 0;
		closedge[i].name = name;
		closedge[i].adjvex = 0;
	}//for

	for (int i = 0; i < vexnum; ++i)
	{
		if (i != k)
		{
			closedge[i].lowcost = arcs[k][i];//从k到i的权重，初始化
			closedge[i].name = name;	//从哪个节点出发到i的名字
			closedge[i].adjvex = i;
		}//if
	}//for
	closedge[k].lowcost = 0;	//0表示已经划入到我们的最小树的部分
	//然后再剩下的节点中寻找最小权值，加入到最小生成树种，直到包括所有节点
	for (int i = 1; i < vexnum; ++i)//也就是还要加入vexnum-1个节点
	{
		//求得当前集合到其他位置最小的路径,对应的节点
		k = minimum();	//得到最小的路径的位置
		std::cout << "从" << closedge[k].name << "=>" << vexs[k] <<"\t路径大小:"<< closedge[k].lowcost << std::endl;
		//然后我们把k号节点划入集合
		closedge[k].lowcost = 0;
		//从新初始化closedge
		for (int i = 0; i < vexnum; ++i)
		{
			//遍历所有的节点，查看集合到相应的顶点的距离
			//选出最小的,也就是把那个并入集合的那个节点到其他的距离，选出更小的
			//也就是k到i是否更小
			if (arcs[k][i] < closedge[i].lowcost)
			{
				//如果找到更小的
				closedge[i].adjvex = i;
				closedge[i].lowcost = arcs[k][i];
				closedge[i].name = vexs[k];
			}//if
		}//for
	}//for
}

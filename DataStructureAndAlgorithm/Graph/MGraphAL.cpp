/****************************************************************************
时间：2015年9月10日20:25:51
作者：cutter_point

文件：MGraphAL.h

功能：实现我们的图的链式表示，邻接表，有向，无向都可以

****************************************************************************/
#include "stdafx.h"
#include "MGraphAL.h"

#include <fstream>
#include <exception>
#include <sstream>
#include <iostream>
#include <queue>


ArcNode::~ArcNode()
{
	delete nextarc;
}

////////////////////////////////////////////////////////////////////////////////

VNode::~VNode()
{
	delete firstarc;
}

////////////////////////////////////////////////////////////////////////////////
MGraphAL::MGraphAL()
{
}


MGraphAL::~MGraphAL()
{
	delete[] vertices;
}

/**
 * 文件格式是：
 *  4 7
 * v1 v2 v3 v4
 * v1:v2 v1:v3 v3:v1 v3:v4 v4:v1 v4:v2 v4:v3
 */
void MGraphAL::create(std::string filename)
{
	if (filename == "")
		return;
	std::ifstream in(filename);
	if (!in.is_open())
		throw std::exception("文件流打开失败");

	std::string line;
	int num = 1;	//记录行
	//打开文件
	while (std::getline(in, line))
	{
		if (num == 1)
		{
			//第一行，初始化顶点个数和弧的个数
			this->intiVAnum(line);
			++num;
		}//if
		else if (num == 2)
		{
			//第二行初始化数组向量
			this->initVertices(line);
			++num;
		}//else if
		else
		{
			//最后初始化我们的邻接表
			this->initAdjacencyLink(line);
			++num;
		}//else
	}

	//关闭文件流
	in.clear();
	in.close();
}

void MGraphAL::intiVAnum(std::string line)
{
	if (line == "")
		return;
	std::stringstream ss(line);	//字符流
	ss >> vexnum >> arcnum;
}

void MGraphAL::initVertices(std::string line)
{
	if (line == "")
		return;
	std::stringstream ss(line);
	for (int i = 0; i < vexnum; ++i)
	{
		ss >> vertices[i].name;
		//这里也注意一下，把这个指针初始化为nullptr
		vertices[i].firstarc = nullptr;
	}//for
}

void MGraphAL::initAdjacencyOne(std::string record)
{
	if (record == "")
		return;
	//这个是一条弧的记录
	std::string name1 = record.substr(0, 2); //如：v1
	std::string name2 = record.substr(3, 2);
	int i = locateVex(name1); int j = locateVex(name2);
	ArcNode *p = new ArcNode();
	p->adjvex = j;	//这个弧指向的对象的数组的下标位置
	p->nextarc = vertices[i].firstarc;	//头插法，加入到这个链表的头中
	vertices[i].firstarc = p;
}

/**
 *  定位我们的这个向量名称的位置
 */
int MGraphAL::locateVex(std::string name)
{
	if (name == "")
		return -1;
	for (int i = 0; i < vexnum; ++i)
	{
		if (vertices[i].name == name)
		{
			return i;
		}//if
	}//for
}

/**
 *  初始化我们的邻接表的弧
 */
void MGraphAL::initAdjacencyLink(std::string line)
{
	if (line == "")
		return;
	//我们把得到的这一行数据进行分开成一个个记录
	std::stringstream ss(line);
	std::string record;
	while (ss >> record)	//只要字符流还有输入的数据
	{
		this->initAdjacencyOne(record);
	}//while
}

/**
*  对我们的图进行深度优先遍历
*/
void MGraphAL::DFSTraverse()
{
	bool *visited = new bool[vexnum];
	//初始化我们的判断是否遍历过的数组
	for (int i = 0; i < vexnum; ++i)
	{
		visited[i] = false;
	}//for
	//开始选一个起点进行深度遍历
	for (int i = 0; i < vexnum; ++i)
	{
		if (visited[i] == false)
		{
			//深度遍历
			this->DFS(i, visited);
		}//if
	}//for
}

void MGraphAL::DFS(int v, bool *visited)
{
	if (v < 0 || v >= vexnum)
		return;
	visited[v] = true;
	this->visit(v);
	if (vertices[v].firstarc == nullptr)
		return;
	//进行深度递归
	for (ArcNode *w = vertices[v].firstarc; w != nullptr; w = w->nextarc)
	{
		if (visited[w->adjvex] == false)
		{
			//如果这个节点没有被访问过
			DFS(w->adjvex, visited);
		}//if
	}//for
}

void MGraphAL::visit(int v)
{
	std::cout << vertices[v].name << "\t";
}

void MGraphAL::BFSTraverse()
{
	bool *visited = new bool[vexnum];
	for (int i = 0; i < vexnum; ++i)
	{
		visited[i] = false;
	}//for

	//我们创建一个队列，用来保存被访问的父节点，广度优先，我们先把父节点访问完，再依次按照队列进行访问
	std::queue<int> *Q = new std::queue<int>();
	//我们从图的一个顶点开始访问
	for (int i = 0; i < vexnum; ++i)
	{
		if (!visited[i])
		{
			//这个节点没有被访问，我们把他进行入队
			//先进行访问，以免，后面的顶点，有的已经进入队列，但是还没有访问，可能会重复入队
			visited[i] = true; visit(i);
			Q->push(i);
			//只要队列不为空，我们就访问队列中的元素
			while (!Q->empty())
			{
				int u = Q->front(); Q->pop();
				//这个节点是否有子节点
				if (vertices[u].firstarc == nullptr)
				{
					//如果没有子节点，这个节点，也就是没有出度的对象了，那么我们就退出
					break;
				}//if
				//这个节点的子节点，全部访问
				//ArcNode *w = vertices[u].firstarc;
				//while (w != nullptr)
				//{
					//出度对象是否已经被访问检查
				//	if (!visited[w->adjvex])
				//	{
						//然后我们把我们访问的这个节点，加入到队列中，等这一层访问完了之后，队列出队的顶点就是出度对象的节点
						//从而广度对下一层次的顶点进行访问
						//这里是吧当前顶点的所有子节点，全部入队
				//		visited[w->adjvex] = true; visit(w->adjvex);
				//		Q->push(w->adjvex);
				//	}//if
				//	w = w->nextarc;
				//}//while
				
				for (ArcNode *w = vertices[u].firstarc; w != nullptr; w = w->nextarc)
				{
					//出度对象是否已经被访问检查
					if (!visited[w->adjvex])
					{
						//然后我们把我们访问的这个节点，加入到队列中，等这一层访问完了之后，队列出队的顶点就是出度对象的节点
						//从而广度对下一层次的顶点进行访问
						//这里是吧当前顶点的所有子节点，全部入队
						visited[w->adjvex] = true; visit(w->adjvex);
						Q->push(w->adjvex);
					}//if
				}//for
			}//while
		}//if
	}//for
}


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
#include <stack>

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
	delete[] ve;
	delete[] vl;
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

/**
 *  创建我们的邻接表，带权值的
 * 文件格式是：
 *  4 7
 * v1 v2 v3 v4
 * v1:v2:7 v1:v3:2 v3:v1:3 v3:v4:4 v4:v1:5 v4:v2:6 v4:v3:1
 */
void MGraphAL::createWithWeight(std::string filename)
{
	if (filename == "")
		throw std::exception("文件名为空");
	std::ifstream in(filename);
	if (!in.is_open())
	{
		throw std::exception("文件流打开失败");
	}//if
	std::string line;
	int num = 1; //行数，用来控制输出
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
			this->initAdjacencyLinkWithWeight(line);
			++num;
		}//else
	}//while

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

void MGraphAL::initAdjacencyOneWithWeight(std::string record)
{
	if (record == "")
		return;
	//一条记录 v1:v2:7
	std::string name1 = record.substr(0, 2);
	std::string name2 = record.substr(3, 2);
	int weight = atoi(record.substr(6, 1).c_str());
	int i = locateVex(name1); int j = locateVex(name2);
	ArcNode *p = new ArcNode();
	p->adjvex = j;	//这个弧指向的下一个节点
	p->weight = weight;	//权值
	p->nextarc = vertices[i].firstarc;	//把这个节点加入到这个链表的头
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

void MGraphAL::initAdjacencyLinkWithWeight(std::string line)
{
	if (line == "")
		return;
	//我们把得到的这一行数据分开
	std::stringstream ss(line);
	std::string record;
	while (ss >> record)
	{
		this->initAdjacencyOneWithWeight(record);
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


/**
 * 把我们的邻接表图，改造成一个以孩子兄弟链表的存储结构
 */
CSNode** MGraphAL::DFSForest()
{
	//建立无向图的深度优先生成森林的链表
	CSNode **root = new CSNode*();
	CSNode *t = nullptr, *q = nullptr;
	bool *visited = new bool[vexnum];	//用来判断这个节点是否已经被遍历过
	for (int i = 0; i < vexnum; ++i)
	{
		visited[i] = false;
	}//for

	//遍历所有的节点
	int n = 0;
	for (int i = 0; i < vexnum; ++i)
	{
		t = root[n];
		if (!visited[i])
		{
			CSNode *p = new CSNode();
			p->name = vertices[i].name;	//得到名字
			//判断根节点是不是空的
			if (t == nullptr)
			{
				t = p;
				q = t;
			}//if
			else
			{
				//如果不是第一棵生成树的根
				q->nextSibling = p;
			}//else

			q = p;	//把q指向下一个兄弟
			DFSTree(i, p, visited);
			++n;
		}//if
	}//for

	return root;
}

/**
 * 这个函数的作用是从第V个顶点出发深度优先遍历图G，建立以T为根的生成树
 * 深度优先遍历
 */
void MGraphAL::DFSTree(int v, CSNode *r, bool *visited)
{
	visited[v] = true;	//把当前节点访问掉
	//设定一个标志，用来确定是不是第一个t下面第一个子树
	bool first = true;
	CSNode *q = nullptr;
	//访问的当前顶点是否有联通量
	if (vertices[v].firstarc == nullptr)
		return;
	for (ArcNode *w = vertices[v].firstarc; w != nullptr; w = w->nextarc)
	{
		//首先查看这个节点是否已经被查看
		if (!visited[w->adjvex])
		{
			CSNode *p = new CSNode();
			p->name = vertices[w->adjvex].name;
			//看看是不是第一次访问
			if (first)
			{
				//如果是这个顶点的开始的第一个节点，那么就作为节点的孩子节点
				r->firstchild = p;
				first = false;
				q = r;	//那么我们的指针q指向我们的前面的父节点
			}//if
			else
			{
				//邻接矩阵的第一个节点是我们的孩子节点，其他的节点是这个孩子节点的兄弟节点
				q->nextSibling = p;
			}//else
			//q = p;
			DFSTree(w->adjvex, p, visited);
		}//if
	}//for
}


/**
 *  初始化一个顶点的入度的数值
 */
void MGraphAL::OneInDegree(int i)
{
	ArcNode *p = vertices[i].firstarc;
	if (p == nullptr)
	{
		return;
	}//if

	for (; p != nullptr; p = p->nextarc)
	{
		indegree[p->adjvex]++;	//把我们的入度个数++
	}//for
}

/**
 *  求出我们所有顶点的所有入度
 */
void MGraphAL::findInDegree()
{
	//首先初始化我们的数组
	for (int i = 0; i < vexnum; ++i)
	{
		indegree[i] = 0;
	}//for

	for (int i = 0; i < vexnum; ++i)
	{
		this->OneInDegree(i);
	}//for
}

/**
 *  对我们的图进行拓扑排序
 */
void MGraphAL::topologicalSort()
{
	//首先初始化我们的入度数组
	this->findInDegree();
	//建立一个栈，用来保存，入度变为0了，也就是可以删除出去作为拓扑排序的位置了
	std::stack<int> *s = new std::stack<int>();
	//把初始的所有的0号入度顶点，入栈
	for (int i = 0; i < vexnum; ++i)
	{
		if (indegree[i] == 0)
		{
			s->push(i);	//把i号压入
		}//if
	}//for

	int count = 0;	//用来统计拓扑排序的结果又那些
	while (!s->empty())
	{
		//当非空的时候，我们就进行相应的操作，一直下去，当弹出循环
		//如果个数比顶点数还少的话，那么就，说明我们的图有回路
		int i = s->top(); s->pop();
		++count;
		//输出相应的顶点
		std::cout << vertices[i].name << "\t" << std::endl;
		//把相应的连接的顶点入度减去这个节点出来的弧
		ArcNode *p = vertices[i].firstarc;
		if (p == nullptr)
			break;
		for (; p != nullptr; p = p->nextarc)
		{
			int k = p->adjvex;	//得到下一个对象的顶点位置
			//减一
			indegree[k]--;
			//如果恰好变为0，那么就入栈
			if (indegree[k] == 0)
			{
				s->push(k);
			}//if
		}//for
	}//while

	//最后如果没有统计全，那么就是会有回环
	if (count < vexnum)
	{
		std::cout << "图中有回环" << std::endl;
	}//if
	else
	{
		std::cout << "OK" << std::endl;
	}
}


/**
 *  求我们图的各个节点的最早发生时间
 *	t是用来存放我们的拓扑排序的，用栈，输出的时候就是逆序
 */
bool MGraphAL::topologicalOrder(std::stack<int> *t)
{
	int count = 0; //用来计数
	memset(ve, 0, vexnum * sizeof(int)); //把最早发生时间初始化为0
	//建立栈S，对所有的0入度节点进行入栈
	std::stack<int> *s = new std::stack<int>();
	this->findInDegree();	//初始化所有的入度
	for (int i = 0; i < vexnum; ++i)
	{
		if (indegree[i] == 0)
		{
			s->push(i);
		}//if
	}//for
	//对0入度的节点，出栈，
	while (!s->empty())
	{
		int topological = s->top(); s->pop();
		//t存放相应的拓扑数列
		t->push(topological);
		++count;	//如果计数统计的节点最后少于我们的节点数的话说明有回路
		//并遍历节点指向的节点,求出指向节点的最早发生时间
		ArcNode *p = vertices[topological].firstarc;
		if (p == nullptr)	//如果没有指向的节点的话，那么就跳出当前循环
			continue;
		for (; p != nullptr; p = p->nextarc)
		{
			int k = p->adjvex;	//我们节点出度的对象
			//把指向的那个节点的入度减少一个
			if (--indegree[k] == 0)
			{
				//如果变为0，那么就压栈进入
				s->push(k);
			}//if
			//求最早发生的时间
			if (ve[topological] + p->weight > ve[k])
			{
				ve[k] = ve[topological] + p->weight;
			}//if
		}//for
	}//while

	delete s;
	//最后判断循环的结果是否已经含有回路
	if (count < vexnum)
	{
		return false;
	}//if
	else
	{
		return true;
	}//else
}

/**
 *  求关键路径
 */
void MGraphAL::criticalPath()
{
	std::stack<int> *t = new std::stack<int>();
	//判断是否有关键路径
	if (!this->topologicalOrder(t))
	{
		throw std::exception("此图含有回环，不存在关键路径");
	}//if
	//初始化vl,第三个参数是按字节分划分的
	for (int i = 0; i < vexnum; ++i)
	{
		vl[i] = ve[vexnum - 1];
	}//for
	//求最晚开始时间vl
	while (!t->empty())
	{
		//对逆序拓扑节点求最晚开始时间
		int j = t->top(); t->pop();	//当前节点
		//根据其出度对象的最晚开始时间，求当前节点的最晚开始时间
		for (ArcNode *p = vertices[j].firstarc; p != nullptr; p = p->nextarc)
		{
			int k = p->adjvex;	//当前指向的节点位置
			int dut = p->weight;	//当前弧的权值
			if (vl[k] - dut < vl[j])
			{
				//如果节点k减去弧的时间到达当前节点的开始时间最小的话
				//也就是当前节点在这个时间开始是最逼近所有后序节点立马可以执行的时间
				vl[j] = vl[k] - dut;
			}//if
		}//for
	}//while
	//输出关键路径
	//关键路径就是ve和vl相等的节点
	for (int i = 0; i < vexnum; ++i)
	{
		//但是我们需要输出所有的关键路径,那么我们就需要根据其后序的节点减去弧之后的值是否相等
		for (ArcNode *p = vertices[i].firstarc; p != nullptr; p = p->nextarc)
		{
			int k = p->adjvex;	//下一个节点的位置
			//得到当前节点的最早开始时间
			int ee = ve[i];
			//得到下一个节点的最晚开始时间-权值之后的值，用来比较
			int el = vl[k] - p->weight;
			char tag = (ee == el) ? '*' : ' ';	//相等就是关键路径
			std::cout << vertices[i].name << "=>" << vertices[k].name << "\t权值:" << p->weight << "\t" << tag << std::endl;
		}//for
	}//for

	//输出最先开始时间
	std::cout << "最先开始时间" << std::endl;
	for (int i = 0; i < vexnum; ++i)
	{
		std::cout << ve[i] << "\t";
	}//for
	std::cout << std::endl;
	//输出最先开始时间
	std::cout << "最晚开始时间" << std::endl;
	for (int i = 0; i < vexnum; ++i)
	{
		std::cout << vl[i] << "\t";
	}//for
	std::cout << std::endl;

	delete t;
}


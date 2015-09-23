/****************************************************************************
时间：2015年9月10日20:25:51
作者：cutter_point

文件：MGraphAL.h

功能：实现我们的图的链式表示，邻接表，有向，无向都可以

****************************************************************************/
#ifndef _MGRAPHAL_H_
#define _MGRAPHAL_H_

#include <string>
#include <stack>

#include "CSNode.h"

class ArcNode
{
	friend class MGraphAL;
public:
	ArcNode(){ nextarc = nullptr; }
	~ArcNode();

private:
	/**
	 *  这个弧节点指向的顶点的位置的，数组下标
	 */
	int adjvex;

	/**
	 * 下一条弧的指针
	 */
	ArcNode *nextarc;

	/**
	 *  弧的信息，可以是权值，这里用string代替
	 */
	std::string info;

	/**
	 * 权值
	 */
	int weight;
};

class VNode
{
	friend class MGraphAL;
public:
	VNode(){}
	~VNode();

private:
	/**
	 *  顶点节点的名字
	 */
	std::string name;

	/**
	 * 依附该顶点的第一个弧的指针
	 */
	ArcNode *firstarc;
};


class MGraphAL
{
public:
	/**
	 *  表示顶点的个数的最大个数
	 */
	const static int MAX_VERTEX_NUM = 26;
	MGraphAL();
	~MGraphAL();

	/**
	 * 创建我们的邻接表
	 */
	void create(std::string filename);

	/**
	 *  创建我们的邻接表，带权值的
	 */
	void createWithWeight(std::string filename);

	/**
	 *  对我们的图进行深度优先遍历
	 */
	void DFSTraverse();

	/**
	 *  对我们的图进行广度优先遍历
	 */
	void BFSTraverse();

	/**
	 * 把我们的邻接表图，改造成一个以孩子兄弟链表的存储结构
	 * 这个是基于无向图的深度优先遍历生成森林
	 */
	CSNode** DFSForest();

	/**
	 *  对我们的图进行拓扑排序
	 */
	void topologicalSort();

	/**
	 *  求关键路径
	 */
	void criticalPath();

private:
	/**
	 *  求我们图的各个节点的最早发生时间
	 *	t是用来存放我们的拓扑排序的，用栈，输出的时候就是逆序
	 */
	bool topologicalOrder(std::stack<int> *t);

	/**
	 *这个函数的作用是从第V个顶点出发深度优先遍历图G，建立以T为根的生成树
	 */
	void DFSTree(int v, CSNode *p, bool *visited);

	/**
	 *  访问我们的这个节点
	 */
	void visit(int v);

	/**
	 * 以我们的一个起点进行深度遍历
	 */
	void DFS(int v, bool *visited);

	/**
	 * 初始化我们的顶点个数，根据字符串
	 */
	void intiVAnum(std::string line);

	/**
	 * 初始化我们的顶点数组
	 */
	void initVertices(std::string line);

	/**
	 *  初始化我们的邻接表的一条弧
	 */
	void initAdjacencyOne(std::string record);

	/**
	 *  初始化我们的邻接表的一条弧,带权值
	 */
	void initAdjacencyOneWithWeight(std::string record);

	/**
	 *  初始化我们的邻接表的弧
	 */
	void initAdjacencyLink(std::string line);

	/**
	 *  初始化我们的邻接表的弧,带权值
	 */
	void initAdjacencyLinkWithWeight(std::string line);

	/**
	 *  初始化一个顶点的入度的数值
	 */
	void OneInDegree(int i);

	/**
	 *  求出我们所有顶点的所有入度
	 */
	void findInDegree();

	/**
	 *  定位我们的这个向量名称的位置
	 */
	int locateVex(std::string name);

	/**
	 *  我们的入度个数
	 */
	int indegree[MAX_VERTEX_NUM];

	/**
	 *  存放我们的顶点向量
	 */
	VNode vertices[MAX_VERTEX_NUM];

	/**
	 *  我们的顶点真实个数
	 */
	int vexnum;

	/**
	 *  我们弧的条数
	 */
	int arcnum;

	/**
	 * 存放各个顶点最早发送时间
	 */
	int ve[MAX_VERTEX_NUM];

	/**
	 *  存放各个顶点最晚开始时间
	 */
	int vl[MAX_VERTEX_NUM];
};

#endif //MGRAPHAL_H_
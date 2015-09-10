/****************************************************************************
时间：2015年9月10日20:25:51
作者：cutter_point

文件：MGraphAL.h

功能：实现我们的图的链式表示，邻接表，有向，无向都可以

****************************************************************************/
#ifndef _MGRAPHAL_H_
#define _MGRAPHAL_H_

#include <string>

class ArcNode
{
public:
	ArcNode(){}
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
};

class VNode
{
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

private:
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

};

#endif //MGRAPHAL_H_
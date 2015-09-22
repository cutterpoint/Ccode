/****************************************************************************
时间：2015年8月31日17:23:44
作者：cutter_point

文件：MGraphUDN.h

功能：实现我们的各种图的操作

****************************************************************************/

#ifndef _MGRAPHUDN_H_
#define _MGRAPHUDN_H_

#include <fstream>
#include <string>
#include <iostream>

/**
* 用这个类来存放最小生成树的每个最短的路径
*/
class CloseDge
{
	friend class MGraphUDN;
public:
	CloseDge(){}
	~CloseDge(){}
private:
	/**
	*  到相应的节点的位置
	*/
	int adjvex;


	/**
	*  到这个节点的当前向量中最短的路径
	*/
	int lowcost;

	/**
	 * 我们节点的名字
	 */
	std::string name;
};

//我们的无向网类
class MGraphUDN
{
public:
	static const int MAX_VERTEX_NUM = 26;	//我们图的最多顶点个数
	static const int MAX_MAXTRIX_NUM = INT_MAX;
	MGraphUDN();
	~MGraphUDN();
	MGraphUDN(std::string filename);

	/**
	 *  创建我们的邻接矩阵
	 */
	void createUDN();

	/**
	 * 输出矩阵
	 */
	void printMaxtrix();

	/**
	 *  最小生成树
	 */
	void miniSpanTree_PRIM(std::string name);

private:
	std::string vexs[MAX_VERTEX_NUM];	//存放顶点
	int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//存放矩阵数组
	int vexnum;	//顶点个数
	int arcnum;		//弧的个数，也就是我们图的边数
	std::string filename;	//我们资源文件名
	CloseDge closedge[MAX_VERTEX_NUM];

	/**
	 * 我们用一个函数来确定我们这个顶点的位置
	 */
	int locateVex(std::string u);

	/**
	 * 从文件中读取数据初始化我们的成员变量
	 */
	void initData(std::string filename);

	/**
	 * 得到我们：分割的位置
	 */
	int getIndexOfFlag(char *begin, char *end, char flag);

	/**
	 * 初始化我们的无向网的数据
	 * 初始化 顶点， 弧 的数量，也就是int vexnum  int arcnum
	 */
	void initNum(char *buf, int splitindex, int length);

	/**
	 * 初始化我们的string vexs[MAX_VERTEX_NUM]，也就是初始化我们的顶点向量
	 */
	void initVexs(char *buf, char flag, int length);

	/**
	 * 初始化我们的邻接矩阵需要的参数
	 */
	void initvvw(char *buf, int length);

	/**
	 * 初始化我们的邻接矩阵
	 */
	void initMatrix(std::string v1, std::string v2, int weight);

	/**
	 *  在求最小生成树的时候，这个用来
	 *  求出closedge中最小的那个节点位置
	 */
	int minimum();
};

#endif //_MGRAPHUDN_H_
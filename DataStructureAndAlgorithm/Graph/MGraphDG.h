/****************************************************************************
时间：2015年9月6日15:15:01
作者：cutter_point

文件：MGraphDG.h

功能：实现我们的无向图的构建，采用十字链表存储表示

****************************************************************************/

#ifndef _MGRAPHDG_H_
#define _MGRAPHDG_H_

#include <string>
#include <fstream>

class ArcBox;	//我们的弧节点类

//顶点节点
class VexNode
{
	friend class MGraphDG;
public:
	VexNode(){}
	~VexNode();
private:
	/**
	 *  节点信息，这里用节点名代替
	 */
	std::string nodeName;

	/**
	 *  分别指向一条入弧和出弧
	 */
	ArcBox *firstin, *firstout;
};

//我们的弧节点类
class ArcBox
{
	friend class MGraphDG;
public:
	ArcBox(){}
	~ArcBox();
private:
	/**
	 *  指向该弧的尾和头顶点的位置
	 */
	int tailvex, headvex;

	/**
	 *  分别是弧头相同和弧尾相同的弧的链域
	 */
	ArcBox *hlink, *tlink;

	/**
	 *  弧的信息，比如权值等等，这里我们可以设定一个字符串来描述信息
	 */
	std::string info;
};

//十字链表存储表示,我们的有向图
class MGraphDG
{
public:
	/**
	 *  顶点的数量
	 */
	static const int MAX_VERTEX_NUM = 26;
	MGraphDG();
	~MGraphDG();
private:

	/**
	 *  我们顶点的数组
	 */
	VexNode xlist[MAX_VERTEX_NUM];
	
	/**
	 *  我们图的顶点数，弧数
	 */
	int vexnum, arcnum;

	/**
	 *  读取文件
	 */
	void readFile(std::string filename);

	/**
	 *  初始化我们的数据成员，顶点数和弧数
	 */
	void intiVAnum(std::string line);

	/**
	 *  初始化我们的顶点数组
	 */
	void initXlist(std::string line);

	/**
	 *  初始化我们各个弧和十字链表
	 */
	void initLink(std::string line);

	/**
	 *  得到我们的向量在数组中的位置
	 */
	int locateVex(std::string name);
};



#endif //_MGRAPHDG_H_
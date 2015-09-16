/****************************************************************************
时间：2015年9月16日19:08:04
作者：cutter_point

文件：CSNode.h

功能：实现我们的图的链式表示，邻接表，有向，无向都可以

****************************************************************************/

#ifndef _CSNODE_H_
#define _CSNODE_H_

#include <string>

class MGraphAL;

class CSNode
{
	friend class MGraphAL;
public:
	CSNode();
	~CSNode();

private:
	/**
	 * 这个节点的名称
	 */
	std::string name;

	/**
	 * 分别是我们的兄弟孩子链表的第一个子节点和，兄弟节点
	 */
	CSNode *firstchild, *nextSibling;
};

#endif //_CSNODE_H_

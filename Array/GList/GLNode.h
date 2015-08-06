/**
 *功能：这个是实现广义表的存储结构
 *时间：2015年8月4日15:23:26
 *文件：GLNode.h
 *作者：cutter_point
*/

#ifndef _GLNode_H_
#define _GLNode_H_

#include <string>

#include "GLNode.h"

using namespace std;

namespace glist
{
	enum ElemTag
	{
		ATOM,	//原子结构
		LIST	//子表
	};
}

class GLists;

class GLNode
{
	friend class GLists;
public:
	/*
	GLNode();
	GLNode(glist::ElemTag tag, GLNode *tp);
	//value.ptr getUnionp() const;
	~GLNode();
	*/
private:
	glist::ElemTag tag;	//这个用来判断节点是原子的还是子表	
	union
	{
		char atom;	//我们原子节点的值,类型用户指定
		//如果是一个列表的话
		struct
		{
			GLNode *hp, *tp;
		}ptr;
	};
};

#endif/*_GLNode_H_*/


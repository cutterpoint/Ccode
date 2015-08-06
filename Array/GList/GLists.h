/**
*功能：这个是实现广义表的链表，暂时就实现广义表的拷贝，广义表的创建，求广义表的深度一个功能吧，以后如果有机会的话，可以再加
*时间：2015年8月4日16:22:01,2015年8月6日15:02:08
*文件：GLists.h
*作者：cutter_point
*/

#ifndef _GLISTS_H_
#define _GLISTS_H_

#include "GLNode.h"

#include <string>

using namespace std;
using namespace glist;

class GLists
{
public:
	GLists();
	~GLists();
	void GetGList(GLNode *&l);//得到广义表,也就是把广义表给l  
	//求广义表的深度
	int GListDepth(GLNode *l) const;
	//拷贝l，返回一个新的广义表
	GLNode* CopyGList(GLNode *l) const;
private:
	//GLNode *ls;	//这个是广义表
	void CreateGList(GLNode *&l, string &s);		//递归建立广义表,为l建立广义表
	inline void server(string &str, string &hstr);	//这个函数是为了把str分成两部分，也就是第一个','和后面的，或者就是一个单元素
};

#endif/*_GLISTS_H_*/

/**
 *���ܣ������ʵ�ֹ����Ĵ洢�ṹ
 *ʱ�䣺2015��8��4��15:23:26
 *�ļ���GLNode.h
 *���ߣ�cutter_point
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
		ATOM,	//ԭ�ӽṹ
		LIST	//�ӱ�
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
	glist::ElemTag tag;	//��������жϽڵ���ԭ�ӵĻ����ӱ�	
	union
	{
		char atom;	//����ԭ�ӽڵ��ֵ,�����û�ָ��
		//�����һ���б�Ļ�
		struct
		{
			GLNode *hp, *tp;
		}ptr;
	};
};

#endif/*_GLNode_H_*/


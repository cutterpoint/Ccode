/**
*���ܣ������ʵ�ֹ�����������ʱ��ʵ�ֹ����Ŀ����������Ĵ���������������һ�����ܰɣ��Ժ�����л���Ļ��������ټ�
*ʱ�䣺2015��8��4��16:22:01,2015��8��6��15:02:08
*�ļ���GLists.h
*���ߣ�cutter_point
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
	void GetGList(GLNode *&l);//�õ������,Ҳ���ǰѹ�����l  
	//����������
	int GListDepth(GLNode *l) const;
	//����l������һ���µĹ����
	GLNode* CopyGList(GLNode *l) const;
private:
	//GLNode *ls;	//����ǹ����
	void CreateGList(GLNode *&l, string &s);		//�ݹ齨�������,Ϊl���������
	inline void server(string &str, string &hstr);	//���������Ϊ�˰�str�ֳ������֣�Ҳ���ǵ�һ��','�ͺ���ģ����߾���һ����Ԫ��
};

#endif/*_GLISTS_H_*/

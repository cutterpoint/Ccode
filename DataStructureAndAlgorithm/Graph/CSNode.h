/****************************************************************************
ʱ�䣺2015��9��16��19:08:04
���ߣ�cutter_point

�ļ���CSNode.h

���ܣ�ʵ�����ǵ�ͼ����ʽ��ʾ���ڽӱ��������򶼿���

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
	 * ����ڵ������
	 */
	std::string name;

	/**
	 * �ֱ������ǵ��ֵܺ�������ĵ�һ���ӽڵ�ͣ��ֵܽڵ�
	 */
	CSNode *firstchild, *nextSibling;
};

#endif //_CSNODE_H_

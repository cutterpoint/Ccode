/****************************************************************************
ʱ�䣺2015��9��10��20:25:51
���ߣ�cutter_point

�ļ���MGraphAL.h

���ܣ�ʵ�����ǵ�ͼ����ʽ��ʾ���ڽӱ��������򶼿���

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
	 *  ������ڵ�ָ��Ķ����λ�õģ������±�
	 */
	int adjvex;

	/**
	 * ��һ������ָ��
	 */
	ArcNode *nextarc;

	/**
	 *  ������Ϣ��������Ȩֵ��������string����
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
	 *  ����ڵ������
	 */
	std::string name;

	/**
	 * �����ö���ĵ�һ������ָ��
	 */
	ArcNode *firstarc;
};

class MGraphAL
{
public:
	/**
	 *  ��ʾ����ĸ�����������
	 */
	const static int MAX_VERTEX_NUM = 26;
	MGraphAL();
	~MGraphAL();

private:
	/**
	 *  ������ǵĶ�������
	 */
	VNode vertices[MAX_VERTEX_NUM];

	/**
	 *  ���ǵĶ�����ʵ����
	 */
	int vexnum;

	/**
	 *  ���ǻ�������
	 */
	int arcnum;

};

#endif //MGRAPHAL_H_
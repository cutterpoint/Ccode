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
	friend class MGraphAL;
public:
	ArcNode(){ nextarc = nullptr; }
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
	friend class MGraphAL;
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

	/**
	 * �������ǵ��ڽӱ�
	 */
	void create(std::string filename);

	/**
	 *  �����ǵ�ͼ����������ȱ���
	 */
	void DFSTraverse();

	/**
	 *  �����ǵ�ͼ���й�����ȱ���
	 */
	void BFSTraverse();

private:
	/**
	 *  �������ǵ�����ڵ�
	 */
	void visit(int v);

	/**
	 * �����ǵ�һ����������ȱ���
	 */
	void DFS(int v, bool *visited);

	/**
	 * ��ʼ�����ǵĶ�������������ַ���
	 */
	void intiVAnum(std::string line);

	/**
	 * ��ʼ�����ǵĶ�������
	 */
	void initVertices(std::string line);

	/**
	 *  ��ʼ�����ǵ��ڽӱ��һ����
	 */
	void initAdjacencyOne(std::string record);

	/**
	 *  ��ʼ�����ǵ��ڽӱ�Ļ�
	 */
	void initAdjacencyLink(std::string line);

	/**
	 *  ��λ���ǵ�����������Ƶ�λ��
	 */
	int locateVex(std::string name);

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
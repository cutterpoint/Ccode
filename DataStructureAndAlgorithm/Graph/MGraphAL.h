/****************************************************************************
ʱ�䣺2015��9��10��20:25:51
���ߣ�cutter_point

�ļ���MGraphAL.h

���ܣ�ʵ�����ǵ�ͼ����ʽ��ʾ���ڽӱ��������򶼿���

****************************************************************************/
#ifndef _MGRAPHAL_H_
#define _MGRAPHAL_H_

#include <string>
#include <stack>

#include "CSNode.h"

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

	/**
	 * Ȩֵ
	 */
	int weight;
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
	 *  �������ǵ��ڽӱ���Ȩֵ��
	 */
	void createWithWeight(std::string filename);

	/**
	 *  �����ǵ�ͼ����������ȱ���
	 */
	void DFSTraverse();

	/**
	 *  �����ǵ�ͼ���й�����ȱ���
	 */
	void BFSTraverse();

	/**
	 * �����ǵ��ڽӱ�ͼ�������һ���Ժ����ֵ�����Ĵ洢�ṹ
	 * ����ǻ�������ͼ��������ȱ�������ɭ��
	 */
	CSNode** DFSForest();

	/**
	 *  �����ǵ�ͼ������������
	 */
	void topologicalSort();

	/**
	 *  ��ؼ�·��
	 */
	void criticalPath();

private:
	/**
	 *  ������ͼ�ĸ����ڵ�����緢��ʱ��
	 *	t������������ǵ���������ģ���ջ�������ʱ���������
	 */
	bool topologicalOrder(std::stack<int> *t);

	/**
	 *��������������Ǵӵ�V���������������ȱ���ͼG��������TΪ����������
	 */
	void DFSTree(int v, CSNode *p, bool *visited);

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
	 *  ��ʼ�����ǵ��ڽӱ��һ����,��Ȩֵ
	 */
	void initAdjacencyOneWithWeight(std::string record);

	/**
	 *  ��ʼ�����ǵ��ڽӱ�Ļ�
	 */
	void initAdjacencyLink(std::string line);

	/**
	 *  ��ʼ�����ǵ��ڽӱ�Ļ�,��Ȩֵ
	 */
	void initAdjacencyLinkWithWeight(std::string line);

	/**
	 *  ��ʼ��һ���������ȵ���ֵ
	 */
	void OneInDegree(int i);

	/**
	 *  ����������ж�����������
	 */
	void findInDegree();

	/**
	 *  ��λ���ǵ�����������Ƶ�λ��
	 */
	int locateVex(std::string name);

	/**
	 *  ���ǵ���ȸ���
	 */
	int indegree[MAX_VERTEX_NUM];

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

	/**
	 * ��Ÿ����������緢��ʱ��
	 */
	int ve[MAX_VERTEX_NUM];

	/**
	 *  ��Ÿ�����������ʼʱ��
	 */
	int vl[MAX_VERTEX_NUM];
};

#endif //MGRAPHAL_H_
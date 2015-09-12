/****************************************************************************
ʱ�䣺2015��9��10��20:25:51
���ߣ�cutter_point

�ļ���MGraphAL.h

���ܣ�ʵ�����ǵ�ͼ����ʽ��ʾ���ڽӱ��������򶼿���

****************************************************************************/
#include "stdafx.h"
#include "MGraphAL.h"

#include <fstream>
#include <exception>
#include <sstream>
#include <iostream>


ArcNode::~ArcNode()
{
	delete nextarc;
}

////////////////////////////////////////////////////////////////////////////////

VNode::~VNode()
{
	delete firstarc;
}

////////////////////////////////////////////////////////////////////////////////
MGraphAL::MGraphAL()
{
}


MGraphAL::~MGraphAL()
{
	delete[] vertices;
}

/**
 * �ļ���ʽ�ǣ�
 *  4 7
 * v1 v2 v3 v4
 * v1:v2 v1:v3 v3:v1 v3:v4 v4:v1 v4:v2 v4:v3
 */
void MGraphAL::create(std::string filename)
{
	if (filename == "")
		return;
	std::ifstream in(filename);
	if (!in.is_open())
		throw std::exception("�ļ�����ʧ��");

	std::string line;
	int num = 1;	//��¼��
	//���ļ�
	while (std::getline(in, line))
	{
		if (num == 1)
		{
			//��һ�У���ʼ����������ͻ��ĸ���
			this->intiVAnum(line);
			++num;
		}//if
		else if (num == 2)
		{
			//�ڶ��г�ʼ����������
			this->initVertices(line);
			++num;
		}//else if
		else
		{
			//����ʼ�����ǵ��ڽӱ�
			this->initAdjacencyLink(line);
			++num;
		}//else
	}

	//�ر��ļ���
	in.clear();
	in.close();
}

void MGraphAL::intiVAnum(std::string line)
{
	if (line == "")
		return;
	std::stringstream ss(line);	//�ַ���
	ss >> vexnum >> arcnum;
}

void MGraphAL::initVertices(std::string line)
{
	if (line == "")
		return;
	std::stringstream ss(line);
	for (int i = 0; i < vexnum; ++i)
	{
		ss >> vertices[i].name;
		//����Ҳע��һ�£������ָ���ʼ��Ϊnullptr
		vertices[i].firstarc = nullptr;
	}//for
}

void MGraphAL::initAdjacencyOne(std::string record)
{
	if (record == "")
		return;
	//�����һ�����ļ�¼
	std::string name1 = record.substr(0, 2); //�磺v1
	std::string name2 = record.substr(3, 2);
	int i = locateVex(name1); int j = locateVex(name2);
	ArcNode *p = new ArcNode();
	p->adjvex = j;	//�����ָ��Ķ����������±�λ��
	p->nextarc = vertices[i].firstarc;	//ͷ�巨�����뵽��������ͷ��
	vertices[i].firstarc = p;
}

/**
 *  ��λ���ǵ�����������Ƶ�λ��
 */
int MGraphAL::locateVex(std::string name)
{
	if (name == "")
		return -1;
	for (int i = 0; i < vexnum; ++i)
	{
		if (vertices[i].name == name)
		{
			return i;
		}//if
	}//for
}

/**
 *  ��ʼ�����ǵ��ڽӱ�Ļ�
 */
void MGraphAL::initAdjacencyLink(std::string line)
{
	if (line == "")
		return;
	//���ǰѵõ�����һ�����ݽ��зֿ���һ������¼
	std::stringstream ss(line);
	std::string record;
	while (ss >> record)	//ֻҪ�ַ����������������
	{
		this->initAdjacencyOne(record);
	}//while
}

/**
*  �����ǵ�ͼ����������ȱ���
*/
void MGraphAL::DFSTraverse()
{
	bool *visited = new bool[vexnum];
	//��ʼ�����ǵ��ж��Ƿ������������
	for (int i = 0; i < vexnum; ++i)
	{
		visited[i] = false;
	}//for
	//��ʼѡһ����������ȱ���
	for (int i = 0; i < vexnum; ++i)
	{
		if (visited[i] == false)
		{
			//��ȱ���
			this->DFS(i, visited);
		}//if
	}//for
}

void MGraphAL::DFS(int v, bool *visited)
{
	if (v < 0 || v >= vexnum)
		return;
	visited[v] = true;
	this->visit(v);
	if (vertices[v].firstarc == nullptr)
		return;
	//������ȵݹ�
	for (ArcNode *w = vertices[v].firstarc; w->nextarc != nullptr; w = w->nextarc)
	{
		if (visited[w->adjvex] == false)
		{
			//�������ڵ�û�б����ʹ�
			DFS(w->adjvex, visited);
		}//if
	}//for
}

void MGraphAL::visit(int v)
{
	std::cout << vertices[v].name << "\t";
}


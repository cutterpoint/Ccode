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
#include <queue>
#include <stack>

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
	delete[] ve;
	delete[] vl;
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

/**
 *  �������ǵ��ڽӱ���Ȩֵ��
 * �ļ���ʽ�ǣ�
 *  4 7
 * v1 v2 v3 v4
 * v1:v2:7 v1:v3:2 v3:v1:3 v3:v4:4 v4:v1:5 v4:v2:6 v4:v3:1
 */
void MGraphAL::createWithWeight(std::string filename)
{
	if (filename == "")
		throw std::exception("�ļ���Ϊ��");
	std::ifstream in(filename);
	if (!in.is_open())
	{
		throw std::exception("�ļ�����ʧ��");
	}//if
	std::string line;
	int num = 1; //�����������������
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
			this->initAdjacencyLinkWithWeight(line);
			++num;
		}//else
	}//while

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

void MGraphAL::initAdjacencyOneWithWeight(std::string record)
{
	if (record == "")
		return;
	//һ����¼ v1:v2:7
	std::string name1 = record.substr(0, 2);
	std::string name2 = record.substr(3, 2);
	int weight = atoi(record.substr(6, 1).c_str());
	int i = locateVex(name1); int j = locateVex(name2);
	ArcNode *p = new ArcNode();
	p->adjvex = j;	//�����ָ�����һ���ڵ�
	p->weight = weight;	//Ȩֵ
	p->nextarc = vertices[i].firstarc;	//������ڵ���뵽��������ͷ
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

void MGraphAL::initAdjacencyLinkWithWeight(std::string line)
{
	if (line == "")
		return;
	//���ǰѵõ�����һ�����ݷֿ�
	std::stringstream ss(line);
	std::string record;
	while (ss >> record)
	{
		this->initAdjacencyOneWithWeight(record);
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
	for (ArcNode *w = vertices[v].firstarc; w != nullptr; w = w->nextarc)
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

void MGraphAL::BFSTraverse()
{
	bool *visited = new bool[vexnum];
	for (int i = 0; i < vexnum; ++i)
	{
		visited[i] = false;
	}//for

	//���Ǵ���һ�����У��������汻���ʵĸ��ڵ㣬������ȣ������ȰѸ��ڵ�����꣬�����ΰ��ն��н��з���
	std::queue<int> *Q = new std::queue<int>();
	//���Ǵ�ͼ��һ�����㿪ʼ����
	for (int i = 0; i < vexnum; ++i)
	{
		if (!visited[i])
		{
			//����ڵ�û�б����ʣ����ǰ����������
			//�Ƚ��з��ʣ����⣬����Ķ��㣬�е��Ѿ�������У����ǻ�û�з��ʣ����ܻ��ظ����
			visited[i] = true; visit(i);
			Q->push(i);
			//ֻҪ���в�Ϊ�գ����Ǿͷ��ʶ����е�Ԫ��
			while (!Q->empty())
			{
				int u = Q->front(); Q->pop();
				//����ڵ��Ƿ����ӽڵ�
				if (vertices[u].firstarc == nullptr)
				{
					//���û���ӽڵ㣬����ڵ㣬Ҳ����û�г��ȵĶ����ˣ���ô���Ǿ��˳�
					break;
				}//if
				//����ڵ���ӽڵ㣬ȫ������
				//ArcNode *w = vertices[u].firstarc;
				//while (w != nullptr)
				//{
					//���ȶ����Ƿ��Ѿ������ʼ��
				//	if (!visited[w->adjvex])
				//	{
						//Ȼ�����ǰ����Ƿ��ʵ�����ڵ㣬���뵽�����У�����һ���������֮�󣬶��г��ӵĶ�����ǳ��ȶ���Ľڵ�
						//�Ӷ���ȶ���һ��εĶ�����з���
						//�����ǰɵ�ǰ����������ӽڵ㣬ȫ�����
				//		visited[w->adjvex] = true; visit(w->adjvex);
				//		Q->push(w->adjvex);
				//	}//if
				//	w = w->nextarc;
				//}//while
				
				for (ArcNode *w = vertices[u].firstarc; w != nullptr; w = w->nextarc)
				{
					//���ȶ����Ƿ��Ѿ������ʼ��
					if (!visited[w->adjvex])
					{
						//Ȼ�����ǰ����Ƿ��ʵ�����ڵ㣬���뵽�����У�����һ���������֮�󣬶��г��ӵĶ�����ǳ��ȶ���Ľڵ�
						//�Ӷ���ȶ���һ��εĶ�����з���
						//�����ǰɵ�ǰ����������ӽڵ㣬ȫ�����
						visited[w->adjvex] = true; visit(w->adjvex);
						Q->push(w->adjvex);
					}//if
				}//for
			}//while
		}//if
	}//for
}


/**
 * �����ǵ��ڽӱ�ͼ�������һ���Ժ����ֵ�����Ĵ洢�ṹ
 */
CSNode** MGraphAL::DFSForest()
{
	//��������ͼ�������������ɭ�ֵ�����
	CSNode **root = new CSNode*();
	CSNode *t = nullptr, *q = nullptr;
	bool *visited = new bool[vexnum];	//�����ж�����ڵ��Ƿ��Ѿ���������
	for (int i = 0; i < vexnum; ++i)
	{
		visited[i] = false;
	}//for

	//�������еĽڵ�
	int n = 0;
	for (int i = 0; i < vexnum; ++i)
	{
		t = root[n];
		if (!visited[i])
		{
			CSNode *p = new CSNode();
			p->name = vertices[i].name;	//�õ�����
			//�жϸ��ڵ��ǲ��ǿյ�
			if (t == nullptr)
			{
				t = p;
				q = t;
			}//if
			else
			{
				//������ǵ�һ���������ĸ�
				q->nextSibling = p;
			}//else

			q = p;	//��qָ����һ���ֵ�
			DFSTree(i, p, visited);
			++n;
		}//if
	}//for

	return root;
}

/**
 * ��������������Ǵӵ�V���������������ȱ���ͼG��������TΪ����������
 * ������ȱ���
 */
void MGraphAL::DFSTree(int v, CSNode *r, bool *visited)
{
	visited[v] = true;	//�ѵ�ǰ�ڵ���ʵ�
	//�趨һ����־������ȷ���ǲ��ǵ�һ��t�����һ������
	bool first = true;
	CSNode *q = nullptr;
	//���ʵĵ�ǰ�����Ƿ�����ͨ��
	if (vertices[v].firstarc == nullptr)
		return;
	for (ArcNode *w = vertices[v].firstarc; w != nullptr; w = w->nextarc)
	{
		//���Ȳ鿴����ڵ��Ƿ��Ѿ����鿴
		if (!visited[w->adjvex])
		{
			CSNode *p = new CSNode();
			p->name = vertices[w->adjvex].name;
			//�����ǲ��ǵ�һ�η���
			if (first)
			{
				//������������Ŀ�ʼ�ĵ�һ���ڵ㣬��ô����Ϊ�ڵ�ĺ��ӽڵ�
				r->firstchild = p;
				first = false;
				q = r;	//��ô���ǵ�ָ��qָ�����ǵ�ǰ��ĸ��ڵ�
			}//if
			else
			{
				//�ڽӾ���ĵ�һ���ڵ������ǵĺ��ӽڵ㣬�����Ľڵ���������ӽڵ���ֵܽڵ�
				q->nextSibling = p;
			}//else
			//q = p;
			DFSTree(w->adjvex, p, visited);
		}//if
	}//for
}


/**
 *  ��ʼ��һ���������ȵ���ֵ
 */
void MGraphAL::OneInDegree(int i)
{
	ArcNode *p = vertices[i].firstarc;
	if (p == nullptr)
	{
		return;
	}//if

	for (; p != nullptr; p = p->nextarc)
	{
		indegree[p->adjvex]++;	//�����ǵ���ȸ���++
	}//for
}

/**
 *  ����������ж�����������
 */
void MGraphAL::findInDegree()
{
	//���ȳ�ʼ�����ǵ�����
	for (int i = 0; i < vexnum; ++i)
	{
		indegree[i] = 0;
	}//for

	for (int i = 0; i < vexnum; ++i)
	{
		this->OneInDegree(i);
	}//for
}

/**
 *  �����ǵ�ͼ������������
 */
void MGraphAL::topologicalSort()
{
	//���ȳ�ʼ�����ǵ��������
	this->findInDegree();
	//����һ��ջ���������棬��ȱ�Ϊ0�ˣ�Ҳ���ǿ���ɾ����ȥ��Ϊ���������λ����
	std::stack<int> *s = new std::stack<int>();
	//�ѳ�ʼ�����е�0����ȶ��㣬��ջ
	for (int i = 0; i < vexnum; ++i)
	{
		if (indegree[i] == 0)
		{
			s->push(i);	//��i��ѹ��
		}//if
	}//for

	int count = 0;	//����ͳ����������Ľ������Щ
	while (!s->empty())
	{
		//���ǿյ�ʱ�����Ǿͽ�����Ӧ�Ĳ�����һֱ��ȥ��������ѭ��
		//��������ȶ��������ٵĻ�����ô�ͣ�˵�����ǵ�ͼ�л�·
		int i = s->top(); s->pop();
		++count;
		//�����Ӧ�Ķ���
		std::cout << vertices[i].name << "\t" << std::endl;
		//����Ӧ�����ӵĶ�����ȼ�ȥ����ڵ�����Ļ�
		ArcNode *p = vertices[i].firstarc;
		if (p == nullptr)
			break;
		for (; p != nullptr; p = p->nextarc)
		{
			int k = p->adjvex;	//�õ���һ������Ķ���λ��
			//��һ
			indegree[k]--;
			//���ǡ�ñ�Ϊ0����ô����ջ
			if (indegree[k] == 0)
			{
				s->push(k);
			}//if
		}//for
	}//while

	//������û��ͳ��ȫ����ô���ǻ��лػ�
	if (count < vexnum)
	{
		std::cout << "ͼ���лػ�" << std::endl;
	}//if
	else
	{
		std::cout << "OK" << std::endl;
	}
}


/**
 *  ������ͼ�ĸ����ڵ�����緢��ʱ��
 *	t������������ǵ���������ģ���ջ�������ʱ���������
 */
bool MGraphAL::topologicalOrder(std::stack<int> *t)
{
	int count = 0; //��������
	memset(ve, 0, vexnum * sizeof(int)); //�����緢��ʱ���ʼ��Ϊ0
	//����ջS�������е�0��Ƚڵ������ջ
	std::stack<int> *s = new std::stack<int>();
	this->findInDegree();	//��ʼ�����е����
	for (int i = 0; i < vexnum; ++i)
	{
		if (indegree[i] == 0)
		{
			s->push(i);
		}//if
	}//for
	//��0��ȵĽڵ㣬��ջ��
	while (!s->empty())
	{
		int topological = s->top(); s->pop();
		//t�����Ӧ����������
		t->push(topological);
		++count;	//�������ͳ�ƵĽڵ�����������ǵĽڵ����Ļ�˵���л�·
		//�������ڵ�ָ��Ľڵ�,���ָ��ڵ�����緢��ʱ��
		ArcNode *p = vertices[topological].firstarc;
		if (p == nullptr)	//���û��ָ��Ľڵ�Ļ�����ô��������ǰѭ��
			continue;
		for (; p != nullptr; p = p->nextarc)
		{
			int k = p->adjvex;	//���ǽڵ���ȵĶ���
			//��ָ����Ǹ��ڵ����ȼ���һ��
			if (--indegree[k] == 0)
			{
				//�����Ϊ0����ô��ѹջ����
				s->push(k);
			}//if
			//�����緢����ʱ��
			if (ve[topological] + p->weight > ve[k])
			{
				ve[k] = ve[topological] + p->weight;
			}//if
		}//for
	}//while

	delete s;
	//����ж�ѭ���Ľ���Ƿ��Ѿ����л�·
	if (count < vexnum)
	{
		return false;
	}//if
	else
	{
		return true;
	}//else
}

/**
 *  ��ؼ�·��
 */
void MGraphAL::criticalPath()
{
	std::stack<int> *t = new std::stack<int>();
	//�ж��Ƿ��йؼ�·��
	if (!this->topologicalOrder(t))
	{
		throw std::exception("��ͼ���лػ��������ڹؼ�·��");
	}//if
	//��ʼ��vl,�����������ǰ��ֽڷֻ��ֵ�
	for (int i = 0; i < vexnum; ++i)
	{
		vl[i] = ve[vexnum - 1];
	}//for
	//������ʼʱ��vl
	while (!t->empty())
	{
		//���������˽ڵ�������ʼʱ��
		int j = t->top(); t->pop();	//��ǰ�ڵ�
		//��������ȶ��������ʼʱ�䣬��ǰ�ڵ������ʼʱ��
		for (ArcNode *p = vertices[j].firstarc; p != nullptr; p = p->nextarc)
		{
			int k = p->adjvex;	//��ǰָ��Ľڵ�λ��
			int dut = p->weight;	//��ǰ����Ȩֵ
			if (vl[k] - dut < vl[j])
			{
				//����ڵ�k��ȥ����ʱ�䵽�ﵱǰ�ڵ�Ŀ�ʼʱ����С�Ļ�
				//Ҳ���ǵ�ǰ�ڵ������ʱ�俪ʼ����ƽ����к���ڵ��������ִ�е�ʱ��
				vl[j] = vl[k] - dut;
			}//if
		}//for
	}//while
	//����ؼ�·��
	//�ؼ�·������ve��vl��ȵĽڵ�
	for (int i = 0; i < vexnum; ++i)
	{
		//����������Ҫ������еĹؼ�·��,��ô���Ǿ���Ҫ���������Ľڵ��ȥ��֮���ֵ�Ƿ����
		for (ArcNode *p = vertices[i].firstarc; p != nullptr; p = p->nextarc)
		{
			int k = p->adjvex;	//��һ���ڵ��λ��
			//�õ���ǰ�ڵ�����翪ʼʱ��
			int ee = ve[i];
			//�õ���һ���ڵ������ʼʱ��-Ȩֵ֮���ֵ�������Ƚ�
			int el = vl[k] - p->weight;
			char tag = (ee == el) ? '*' : ' ';	//��Ⱦ��ǹؼ�·��
			std::cout << vertices[i].name << "=>" << vertices[k].name << "\tȨֵ:" << p->weight << "\t" << tag << std::endl;
		}//for
	}//for

	//������ȿ�ʼʱ��
	std::cout << "���ȿ�ʼʱ��" << std::endl;
	for (int i = 0; i < vexnum; ++i)
	{
		std::cout << ve[i] << "\t";
	}//for
	std::cout << std::endl;
	//������ȿ�ʼʱ��
	std::cout << "����ʼʱ��" << std::endl;
	for (int i = 0; i < vexnum; ++i)
	{
		std::cout << vl[i] << "\t";
	}//for
	std::cout << std::endl;

	delete t;
}


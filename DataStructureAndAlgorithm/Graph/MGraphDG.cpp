/****************************************************************************
ʱ�䣺2015��9��6��15:15:01
���ߣ�cutter_point

�ļ���MGraphDG.cpp

���ܣ�ʵ�����ǵ�����ͼ�Ĺ���������ʮ������洢��ʾ

****************************************************************************/

#include "stdafx.h"
#include "MGraphDG.h"

#include <sstream>

/////////////////////////////////////////////////////////////////////////////
////////////////////////////���ǵĶ���ڵ��������///////////////////////////////
VexNode::~VexNode()
{
	delete firstin;
	delete firstout;
}


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////���ǵĻ��ڵ��������////////////////////////////////
ArcBox::~ArcBox()
{
	delete hlink, tlink;
}


/////////////////////////////////////////////////////////////////////////////
///////////////////���ǵ�ʮ������洢��ʾ,���ǵ�����ͼ�������///////////////////////
MGraphDG::MGraphDG()
{

}


MGraphDG::~MGraphDG()
{
	delete[] xlist;
}

/**
 *  ��ȡ�ļ�
 */
void MGraphDG::readFile(std::string filename)
{
	std::ifstream in(filename);
	std::string line;	//һ������
	int num = 0;	//���ǵ�����

	if (in.is_open())
	{
		while (std::getline(in, line, '\n'))
		{
			if (num == 0)
			{
				//��ʼ������������ͻ��ĸ���
				this->intiVAnum(line);
				++num;
			}//if
			else if (num == 1)
			{
				//��ʼ�������ǵĶ�����������
				this->initXlist(line);
				++num;
			}//else if
			else
			{
				//��ʼ�����ǵ�ʮ������
				this->initLink(line);
				++num;
			}
		}//while
		//�ر��ļ���
		in.clear();
		in.close();
	}
}

/**
 *  ��ʼ�����ǵ����ݳ�Ա���������ͻ���
 * ��ʽ��4 7
 */
void MGraphDG::intiVAnum(std::string line)
{
	std::stringstream sstr(line);	//���������Ժܺõش���string����
	std::string num1, num2;
	sstr >> num1 >> num2;	//��ȡ�������ֵ��ַ���
	this->vexnum = atoi(num1.c_str());
	this->arcnum = atoi(num2.c_str());
}

/**
 *  ��ʼ�����ǵĶ�������
 *  ��ʽ��  v1 v2 v3 v4
 */
void MGraphDG::initXlist(std::string line)
{
	std::stringstream ss(line);	//���ǰ��������뵽���ǵ�������
	for (int i = 0; i < vexnum; ++i)
	{
		ss >> xlist[i].nodeName;
	}//for
}

/**
 *  ��ʼ�����Ǹ�������ʮ������
 *  v1:v2 v1:v3 v3:v1 v3:v4 v4:v1 v4:v2 v4:v3
 */
void MGraphDG::initLink(std::string line)
{
	std::stringstream ss(line);	//�ַ���
	for (int k = 0; k < arcnum; ++k)
	{
		std::string temp, name1, name2;
		ss >> temp;	//�õ���һ���ո�֮ǰ������
		name1 = temp.substr(0, 2);
		name2 = temp.substr(3, 2);
		//�����������ֵõ����ǵ�������λ��   i----->j
		int i = this->locateVex(name1);
		int j = this->locateVex(name2);
		//�������ǵĻ��ڵ㣬����ʼ����Ӧ������
		ArcBox *p = new ArcBox();
		//��β����ͷ
		p->tailvex = i; p->headvex = j;
		//�����������Ӧ�Ľڵ�ģ���ͬ�Ļ�ͷ�ͻ�β�Ľڵ㣬������ͷ�巨�����ӵ�һ��
		p->hlink = xlist[j].firstin;  p->tlink = xlist[i].firstout;
		p->info = name1 + "==>" + name2;	//�ڵ���Ϣ
		//���ǰ���������뵽��β�Ľڵ�֮�󣬰�ǰ��Ļ����ӵ��������ĩβ
		xlist[j].firstin = xlist[i].firstout = p;
	}
}

/**
 *  �õ����ǵ������������е�λ��
 */
int MGraphDG::locateVex(std::string name)
{
	if (name == "")
		return -1;
	for (int i = 0; i < vexnum; ++i)
	{
		//Ѱ���������ڵ�λ��
		if (xlist[i].nodeName == name)
		{
			return i;
		}//if
	}//for
}


/****************************************************************************
ʱ�䣺2015��8��31��17:23:44
���ߣ�cutter_point

�ļ���MGraph.cpp

���ܣ�ʵ�����ǵĸ���ͼ�Ĳ���

****************************************************************************/

#include "stdafx.h"
#include "MGraphUDN.h"
#include <iostream>


MGraphUDN::MGraphUDN()
{
}


MGraphUDN::~MGraphUDN()
{
}

MGraphUDN::MGraphUDN(std::string filename)
{
	this->filename = filename;
}

//������һ��������ȷ��������������λ��
int MGraphUDN::locateVex(std::string u)
{
	//ȷ�����ǵ�u�Ƕ��������ĵڼ���
	int i = 0;
	for (; i < vexnum; ++i)
	{
		//�ȽϺ�����ַ��Ƿ�һ��,����ȵ�ʱ�򷵻�0��1>2�������������򷵻ظ���
		if (vexs[i] == u)
		{
			return i;
		}//if
	}//for
	//���û��ƥ�䵽��Ӧ���ַ�
	return -1;
}

void MGraphUDN::createUDN()
{
	this->initData(filename);
}

//���ļ��ж�ȡ���ݳ�ʼ�����ǵĳ�Ա����
//��һ�е���ʶ��   �������������� ���磺��6:10)��ʾ��6�����㣬10����
//�ڶ��е���ʶ��   ��������	���磺��v1 : v2 : v3 : v4 : v5 : v6) 6������
//�����е���ʶ��   ����ÿ�����Ļ�β����ͷ, Ȩֵ ���磺��v1 : v2 : 5 v1 : v4 : 7 .....)
void MGraphUDN::initData(std::string filename)
{
	const int SIZE = 512;	//ÿ�ж�ȡ100���ַ�����������'\0'
	std::ifstream datasource(filename);
	int i = 1; //������ʾ����
	char buf[SIZE];
	//ѭ����ȡÿһ��
	while (datasource.getline(buf, SIZE))
	{
		//������һ�в����ǿյ�
		if (buf[0] != ' ')
		{
			//�����ȵõ����ǵ��ַ�����ʵ����
			int length = 0;
			while (buf[length] != '\0')
			{
				++length;
			}//while
			if (i == 1)
			{
				//��һ���� �������������� ���磺��6:10)��ʾ��6�����㣬10����
				//int vexnum   �������  int arcnum  ���ĸ�����Ҳ��������ͼ�ı���
				//��������'��'�ָ��,���ǽ����⺯��atoi				
				int splitindex = getIndexOfFlag(&buf[0], &buf[length - 1], ':');
				//���ú������г�ʼ��
				this->initNum(buf, splitindex, length);
				++i;
			}//if
			else if (i == 2)
			{
				//�ڶ��������ǵĶ������������Ǳ��浽string vexs[MAX_VERTEX_NUM]��
				//����ѭ������������һ���������Ǿ�ȡһ���������ȡ����һ��
				char flag = ':';	//���Ƿָ��ı�׼
				this->initVexs(buf, flag, length);
				++i;
			}//else if
			else if (i == 3)
			{
				//������  ����ÿ�����Ļ�β����ͷ,Ȩֵ ���磺��v1:v2:5 v1:v4:7 .....)
				//���ÿ���������ÿո�ֿ��ģ� �����������������ʼ�������ǵ�������
				this->initvvw(buf, length);
				i = 1;
			}//else if
		}
		else
			continue;	//��һ��
	}//while
}

//�õ����ǣ��ָ��λ��
int MGraphUDN::getIndexOfFlag(char *begin, char *end, char flag)
{
	//��begin��end�е�һ�������ֵ�λ��
	char *p = begin;
	int index = -1;
	while (p != end + 1)
	{
		++index;
		if (*p == flag)
		{
			//�ַ��õ�ƥ��
			break;
		}//if
		++p;
	}//while

	return index;
}

//��ʼ�� ���㣬 �� ��������Ҳ����int vexnum  int arcnum
void MGraphUDN::initNum(char *buf, int splitindex, int length)
{
	//ǰ�����vecnum,�������arcnum
	char *vecc = new char[splitindex];
	for (int i = 0; i < splitindex; ++i)
		vecc[i] = buf[i];
	vexnum = atoi(vecc);
	char *arcc = new char[length - splitindex - 1];
	for (int i = 0; i < length - splitindex - 1; ++i)
		arcc[i] = buf[i + splitindex + 1];
	arcnum = atoi(arcc);
}

//��ʼ�����ǵ�string vexs[MAX_VERTEX_NUM]��Ҳ���ǳ�ʼ�����ǵĶ�������
//v1:v2:v3:v4:v5:v6
void MGraphUDN::initVexs(char *buf, char flag, int length)
{
	int k = 0;	//���������ǵڼ�������
	for (int j1 = 0, j2 = 0; j1 <= length; ++j1)
	{
		if (buf[j1] == flag || j1 == length)
		{
			std::string s(buf, j2, j1 - j2); //��buf���±���j2���ַ���ʼ������j1-j2���ַ�  
			vexs[k++] = s;
			j2 = j1 + 1;
		}//if
	}//for
}

//��ʼ�����ǵ��ڽӾ���
//v1:v2:5 v1:v4:7 v2:v3:4 v3:v1:8 v3:v6:9 v4:v3:5 v4:v6:6 v5:v4:5 v6:v1:3 v6:v5:1
void MGraphUDN::initvvw(char *buf, int length)
{
	if (buf == nullptr)
		return;
	//�ȰѾ���ȫ����ʼ��Ϊ���޴�
	for (int i = 0; i < vexnum; ++i)
	{
		for (int j = 0; j < vexnum; ++j)
		{
			arcs[i][j] = MAX_MAXTRIX_NUM;
		}//for
	}//for
	for (int i1 = 0, i2 = 0; i1 <= length; ++i1)
	{
		if (buf[i1] == ' ' || i1 == length)
		{
			//һ���ָ�v1:v2:5,
			std::string tempS(buf, i2, i1 - i2);
			i2 = i1 + 1;
			//�ֱ����β����ͷ��Ȩֵ
			std::string v1, v2;
			int weight;
			v1 = tempS.substr(0, 2);
			v2 = tempS.substr(3, 2);
			weight = tempS[6] - '0';
			this->initMatrix(v1, v2, weight);
		}//if
	}//for
}

//��ʼ���ڽӾ����һ������
void MGraphUDN::initMatrix(std::string v1, std::string v2, int weight)
{
	//�ҵ��ڽӾ�����v1λ��β��v2Ϊ��ͷ��λ��
	int i = this->locateVex(v1);
	int j = this->locateVex(v2);
	this->arcs[i][j] = this->arcs[j][i] = weight;
}

/**
* �������
*/
void MGraphUDN::printMaxtrix()
{
	for (int i = 0; i < vexnum; ++i)
	{
		for (int j = 0; j < vexnum; ++j)
		{
			std::cout << arcs[i][j] << "\t";
		}//for
		std::cout << std::endl;
	}//for
}
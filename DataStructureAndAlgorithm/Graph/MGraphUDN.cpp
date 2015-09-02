/****************************************************************************
ʱ�䣺2015��8��31��17:23:44
���ߣ�cutter_point

�ļ���MGraph.cpp

���ܣ�ʵ�����ǵĸ���ͼ�Ĳ���

****************************************************************************/

#include "stdafx.h"
#include "MGraphUDN.h"


MGraphUDN::MGraphUDN()
{
}


MGraphUDN::~MGraphUDN()
{
}

//������һ��������ȷ��������������λ��
int MGraphUDN::locateVex(char u)
{
	//ȷ�����ǵ�u�Ƕ��������ĵڼ���
	int i = 0;
	for (; i < vexnum; ++i)
	{
		//�ȽϺ�����ַ��Ƿ�һ��,����ȵ�ʱ�򷵻�0��1>2�������������򷵻ظ���
		if (strcmp(&vexs[i], &u) == 0)
		{
			return i;
		}//if
	}//for
	//���û��ƥ�䵽��Ӧ���ַ�
	return -1;
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
	while (datasource.get(buf, SIZE))
	{
		//������һ�в����ǿյ�
		if (buf[0] != ' ')
		{
			if (i == 1)
			{
				//��һ���� �������������� ���磺��6:10)��ʾ��6�����㣬10����
				//int vexnum   �������  int arcnum  ���ĸ�����Ҳ��������ͼ�ı���
				//��������'��'�ָ��,���ǽ����⺯��atoi
				//�����ȵõ����ǵ��ַ�����ʵ����
				int length = 0;
				while (buf[length] != '\0')
				{
					++length;
				}//while
				int splitindex = getIndexOfFlag(&buf[0], &buf[length - 1], ':');
				//ǰ�����vecnum,�������arcnum
				char *vecc = new char[splitindex];
				for (int i = 0; i < splitindex; ++i)
					vecc[i] = buf[i];
				vexnum = atoi(vecc);
				char *arcc = new char[length - splitindex - 1];
				for (int i = 0; i < length - splitindex - 1; ++i)
					arcc[i] = buf[i + splitindex + 1];
				arcnum = atoi(arcc);
				++i;
			}//if
			else if (i == 2)
			{
				//�ڶ��������ǵĶ������������Ǳ��浽char vexs[MAX_VERTEX_NUM]��
				int 
				++i;
			}//else if
			else if (i == 3)
			{
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

// Test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

int getIndexOfFlag(char *begin, char *end, char flag)
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

void Test2()
{
	//��һ���� �������������� ���磺��6:10)��ʾ��6�����㣬10����
	//int vexnum   �������  int arcnum  ���ĸ�����Ҳ��������ͼ�ı���
	//��������'��'�ָ��,���ǽ����⺯��atoi
	//�����ȵõ����ǵ��ַ�����ʵ����
	int length = 0;
	string buf = "6:10";
	while (buf[length] != '\0')
	{
		++length;
	}//while
	int splitindex = getIndexOfFlag(&buf[0], &buf[length - 1], ':');
	//ǰ�����vecnum,�������arcnum
	char *vecc = new char[splitindex];
	for (int i = 0; i < splitindex; ++i)
		vecc[i] = buf[i];
	int vexnum = atoi(vecc);
	cout << vexnum << endl;
	char *arcc = new char[length - splitindex - 1];
	for (int i = 0; i < length - splitindex - 1; ++i)
		arcc[i] = buf[i + splitindex + 1];
	int arcnum = atoi(arcc);
	cout << arcnum << endl;
}

void Test3(char buf[], int length)
{
	string vexs[100];
	//�ڶ��������ǵĶ������������Ǳ��浽string vexs[MAX_VERTEX_NUM]��
	//����ѭ������������һ���������Ǿ�ȡһ���������ȡ����һ��
	int k = 0;	//���������ǵڼ�������
	char flag = ':';	//���Ƿָ��ı�׼
	for (int j1 = 0, j2 = 0; j1 <= length; ++j1)
	{
		if (buf[j1] == flag)
		{
			std::string s(buf, j2, j1 - j2); //��buf�±�Ϊj2���ַ���ʼ������j1-j2���ַ�  
			vexs[k++] = s;
			j2 = j1 + 1;
		}//if
	}//for
}

void Test()
{
	std::string line = "6:10";
	char *begin = &line[0];
	char *end = &line[line.size()-1];
	char flag = ':';
	cout << getIndexOfFlag(begin, end, flag) << endl;
	//=================================
	char buf[17] = { 'v', '1', ':', 'v', '2', ':', 'v', '3', ':', 'v', '4', ':', 'v', '5', ':', 'v', '6' };
	int length = 17;
	Test3(buf, length);
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test2();
	Test();
	return 0;
}


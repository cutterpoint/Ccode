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

void Test()
{
	std::string line = "6:10";
	char *begin = &line[0];
	char *end = &line[line.size()-1];
	char flag = ':';
	cout << getIndexOfFlag(begin, end, flag) << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test2();
	return 0;
}


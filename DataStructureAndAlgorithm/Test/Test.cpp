// Test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>

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

void Test3()
{
	int a[] = { 1, 2, 3, 4, 5, 6 };
	int b[6];
	cout << sizeof(a) << endl;
	memcpy(b, &a, sizeof(a));
	for (int i = 0; i < 6; ++i)
	{
		cout << b[i] << "\t" << endl;
	}
}

void test4()
{
	long x = 19 / 5 * 2;
	cout << x << endl;
}

int foo()
{
	static int n = 0;
	return ++n;
}

void test5()
{
	for (int i = 0; i < 5; ++i)
		cout << foo() << endl;
}

struct DATA
{
	char c;
	int n;
};

void test6()
{
	DATA *p = new DATA[100];
	delete[] p;
	printf("%d", sizeof(DATA));
}

void test7()
{
	int a = 123;
	const int &b = a;
	a += b;
	cout << b << endl;
}

void test8()
{
	int n = 0;
	cout << n << endl;
}

void test9()
{
	int *p = new int;
	*p = 3;
}

void test10()
{
	int x = 0x30;
	printf("%d", x);
}

enum{RED, GREEN, BLUE, WHITE};

void test11()
{
	cout << BLUE << endl;
}

void test12()
{
	vector<long> x;
	vector<long>::iterator it = x.begin() + 2;
	x.resize(20);
	*it = 9;
	cout << x[0] << x[1] << x[2] << endl;
}

struct POINT
{
	int x;
	int y;
};

void createpoints(POINT *p, int nCount)
{
	if (nCount <= 0)
		p = nullptr;
	else
		p = new POINT[nCount];
}

void test13()
{
	POINT *p = nullptr;
	const int nCount = 64;
	createpoints(p, nCount);
	for (unsigned int i = 0; i <= nCount; ++i)
	{
		cout << "{" << p->x;
	}//for
}

int _tmain(int argc, _TCHAR* argv[])
{
	//Test2();
	//Test();
	//Test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();
	//test10();
	//test11();
	//test12();
	test13();
	return 0;
}


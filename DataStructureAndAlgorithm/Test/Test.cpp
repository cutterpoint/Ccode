// Test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

int getIndexOfFlag(char *begin, char *end, char flag)
{
	//从begin到end中第一个：出现的位置
	char *p = begin;
	int index = -1;
	while (p != end + 1)
	{
		++index;
		if (*p == flag)
		{
			//字符得到匹配
			break;
		}//if
		++p;
	}//while

	return index;
}

void Test2()
{
	//第一行是 顶点数：弧度数 例如：（6:10)表示有6个顶点，10个弧
	//int vexnum   顶点个数  int arcnum  弧的个数，也就是我们图的边数
	//我们是用'：'分割的,我们借助库函数atoi
	//我们先得到我们的字符的真实长度
	int length = 0;
	string buf = "6:10";
	while (buf[length] != '\0')
	{
		++length;
	}//while
	int splitindex = getIndexOfFlag(&buf[0], &buf[length - 1], ':');
	//前面的是vecnum,后面的是arcnum
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


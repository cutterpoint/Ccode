/**
*���ܣ������ʵ�ֹ����������������
*ʱ�䣺2015��8��4��16:22:01��2015��8��5��15:06:50
*�ļ���main.cpp
*���ߣ�cutter_point
*/

#include <iostream>
#include <string>

#include "GLists.h"

using namespace std;

int main()
{
	cout << "hello" << endl;
	GLists g1;
	GLNode *t = nullptr, *l = nullptr;
	//��ʼ���������
	g1.GetGList(l);
	t = g1.CopyGList(l);
	cout << g1.GListDepth(l) << endl;
	cout <<"����֮��" << g1.GListDepth(t) << endl;
	return 0;
}

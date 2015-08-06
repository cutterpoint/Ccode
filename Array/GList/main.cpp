/**
*功能：这个是实现广义表的链表的主函数
*时间：2015年8月4日16:22:01，2015年8月5日15:06:50
*文件：main.cpp
*作者：cutter_point
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
	//开始创建广义表
	g1.GetGList(l);
	t = g1.CopyGList(l);
	cout << g1.GListDepth(l) << endl;
	cout <<"拷贝之后：" << g1.GListDepth(t) << endl;
	return 0;
}

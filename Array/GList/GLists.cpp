/**
*功能：这个是实现广义表的链表
*时间：2015年8月4日16:22:01
*文件：GLists.h
*作者：cutter_point
*/

#include <iostream>
#include <string>

#include "GLists.h"

GLists::GLists()
{
}

/***********************************
 *求广义表的深度
 *当这个是空表的时候深度是：1
 *当这个是原子项的时候深度是：0
 *最后归纳：深度是=1 + MAX：1<=i<=n{Depth（a:i）}  递归求值
 ***********************************/
int GLists::GListDepth(GLNode *l) const
{
	//我们采用递归，那么递归终止条件2个
	if (l == nullptr)	//如果是空表
	{
		return 1;
	}
	if (l->tag == ATOM)	//如果是原子元素
		return 0;
	//递归计算
	GLNode *p = l;
	int max = 0, dep = 0;
	for (; p != nullptr; p = p->ptr.tp)
	{
		dep = GListDepth(p->ptr.hp);	//递归求得这个节点的深度
		if (dep > max)
			max = dep;
	}

	return max + 1;	//这个深度是各个元素最大值 + 1，也就是加上本身的深度
}//GListDepth


/***********************************
*复制广义表
*由于任何一个非空广义表均可以分解成表头和表尾，也就是一对确定的表头和表尾可唯一确定一个广义表
***********************************/
GLNode* GLists::CopyGList(GLNode *l) const
{
	//创建一个我们要复制出来的广义表节点
	GLNode *t = nullptr, *q, *p;
	//判断是不是空表
	if (!l)
		t = nullptr;
	else
	{
		//我们要复制的对象不是空的，那么我们创建一个空间节点来存放我们的结果
		t = new GLNode();
		//如果这个当前表示原子类型的
		if (l->tag == glist::ATOM)
		{
			t->tag = glist::ATOM;
			t->atom = l->atom;
		}//if
		else
		{
			//如果不是原子类型的节点，那我们递归下一个节点
			t->tag = glist::LIST;	//那么就是表节点
			//那么我们的头结点指向的表复制过来
			t->ptr.hp = CopyGList(l->ptr.hp);
			//下一个节点也复制过来
			t->ptr.tp = CopyGList(l->ptr.tp);
		}
	}//else
	return t;
}

/***********************************
*根据给定字符串s，从l递归创建广义表  
* GLNode<T> *ls;	//这个是广义表
* 就是给上面这个赋值，用s
***********************************/
void GLists::CreateGList(GLNode *&l, string &s)
{
	//创建变量
	GLNode *q, *p;
	string sub, hsub;
	if (s == "()")	//如果是一个空括号的话
		l = nullptr;
	else
	{
		l = new GLNode;	//建立表节点

		if (s.size() == 1)	//这个也就是只有一个元素(e),到了这里第一趟的时候是已经去掉了括号了
		{
			(*l).tag = glist::ATOM;	//原子类型
			(*l).atom = s[0];	//取出这个元素,(e),也就是第二个元素
		}
		else
		{
			(*l).tag = glist::LIST;
			p = l;	//把l的地址给p
			sub = s.substr(1, s.size() - 2);	//去掉括号(),这个的意思就是把第一个之后的开始取，取size()-2个元素
			do		//根据得到的字符串，建立链表,同层次的
			{
				/*第一个参数是后边部分，第二个是前面的部分，也就是","之前的部分*/
				server(sub, hsub);	//从sub中分离出表的头部和后半部
				CreateGList(p->ptr.hp, hsub);	//把前面的部分建立链表,从头结点一直建立下去，直到原子节点
				q = p;	//把当前的p指针赋值给q，我们用q来做游标，进行同层次的创建广义表
				if (!sub.empty())	//后面的字符不是空的
				{
					p = new GLNode();	//我们给p指向一个新的空间
					p->tag = glist::LIST;
					//我们把一个节点接到原来的节点后面，也就建立同层次节点
					q->ptr.tp = p;	//q，也就是原来的链表节点的尾部指向p
				}
			} while (!sub.empty());
		}
	}
}

/***********************************
*这个函数是为了把str分成两部分，也就是第一个','和后面的，或者就是一个单元素
***********************************/
inline void GLists::server(string &str, string &hstr)
{
	//n是我们原始字符串的长度，i是我们遍历字符串的指示位置，k是我们括号的匹配问题
	int n = str.size(), i = 0, k = 0;
	do
	{
		//我们的i下标从0开始
		if (str[i] == '(') ++k;	//当有一个左括号，也就是括号开始的时候，添加一个
		if (str[i] == ')') --k;	//当有一个右括号的时候，也就是一个括号得到匹配的时候，我们减少一个
		++i;
	} while (i < n && (str[i] != ',' || k != 0));	//当遇到第一个逗号的时候分割字符串，或者括号匹配玩的时候分割，直到字符串末尾

	//分割的位置找到之后开始分割
	if (i < n)
	{
		//字符串可以被分割为两部分，去掉“,”
		hstr = str.substr(0, i);	//前面部分
		str = str.substr(i + 1, n - i - 1);	//后面部分
	}
	else
	{
		hstr = str;
		//没有后面的括号，那么就进行清空
		str.clear();
	}

}

/***********************************
*得到我们的广义表
***********************************/
void GLists::GetGList(GLNode *&l)
{
	std::cout << "输入一个字符串(())类型:如（a, b, (c, d, e, (f, g))）" << std::endl;
	string str;
	std::cin >> str;
	CreateGList(l, str);
}

GLists::~GLists()
{
}

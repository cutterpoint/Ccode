/****************************************************************************
时间：2015年8月30日16:20:40
作者：cutter_point

文件：main.cpp

功能：实现我们的对一个集合的所有子集的遍历

****************************************************************************/

#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;

/**
 *		例如：1,2,3的所有子集
 *						{}
 *				/				\
 *			  {1}				   {}
 *			/	  \				/	    \
 *		  {1,2}	   {1}		  {2}       {}
 *		/	 \	  /	  \		 /   \    /    \
 *	{1,2,3} {1,2}{1,3}{1}  {2,3} {2} {3}   {}
 *	我们的根开始就是我们B的开始，然后不断对1,2,3遍历到的数进行取舍
 */
void GetPowerSet(int i, vector<int> A, vector<int> B)
{
	if (i >= A.size())
	{
		//如果遍历到了数组的末尾，我们就输出
		for (int i = 0; i < B.size(); ++i)
		{
			cout << B[i];
		}//for
		cout << endl;
	}//if
	else
	{
		//首先我们获取集合中第i个元素
		int temp = A[i];
		//先取这个元素，看看结果
		B.push_back(temp);
		GetPowerSet(i + 1, A, B);
		//当舍去这个元素的时候
		B.pop_back();
		GetPowerSet(i + 1, A, B);
	}//else
}

void Test()
{
	int a[] = { 1, 2, 3 };
	vector<int> A(a, a + 3);
	vector<int> B;
	GetPowerSet(0, A, B);
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test();
	return 0;
}


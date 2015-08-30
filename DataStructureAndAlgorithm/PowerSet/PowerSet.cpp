/****************************************************************************
ʱ�䣺2015��8��30��16:20:40
���ߣ�cutter_point

�ļ���main.cpp

���ܣ�ʵ�����ǵĶ�һ�����ϵ������Ӽ��ı���

****************************************************************************/

#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;

/**
 *		���磺1,2,3�������Ӽ�
 *						{}
 *				/				\
 *			  {1}				   {}
 *			/	  \				/	    \
 *		  {1,2}	   {1}		  {2}       {}
 *		/	 \	  /	  \		 /   \    /    \
 *	{1,2,3} {1,2}{1,3}{1}  {2,3} {2} {3}   {}
 *	���ǵĸ���ʼ��������B�Ŀ�ʼ��Ȼ�󲻶϶�1,2,3��������������ȡ��
 */
void GetPowerSet(int i, vector<int> A, vector<int> B)
{
	if (i >= A.size())
	{
		//����������������ĩβ�����Ǿ����
		for (int i = 0; i < B.size(); ++i)
		{
			cout << B[i];
		}//for
		cout << endl;
	}//if
	else
	{
		//�������ǻ�ȡ�����е�i��Ԫ��
		int temp = A[i];
		//��ȡ���Ԫ�أ��������
		B.push_back(temp);
		GetPowerSet(i + 1, A, B);
		//����ȥ���Ԫ�ص�ʱ��
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


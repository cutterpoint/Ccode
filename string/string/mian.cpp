/*
*���ܣ���������ִ�в߲���
*ʱ�䣺2015��7��15��17:16:01,2015��7��21��20:33:10��2015��7��26��16:37:31
*�ļ���SString.h
*���ߣ�cutter_point
*/

#include <iostream>

#include "kmp.h"
#include "SString.h"

using namespace std;


int main()
{
	unsigned char c[] = " acabaabaabcacaabc";
	unsigned char c2[] = " abaabcac";
	SString T;
	T.setCh(c2);
	T.setLength(8);
	KmpString *ks = new KmpString(c, 16);
	ks->get_next(T);

	int *p = ks->getNext();

	for (int i = 0; i < 9; ++i)
	{
		cout << *(p + i) << "\t";
	}
	cout << endl;
	cout <<"���ǵ��Ӵ�����������ʼ��λ�ã�"<< ks->index_KMP(T, 1) << endl;

	return 0;
}

/*
int main()
{
	unsigned char ch[] = {' ', 'a','b','a','b','c','a','b','c','a','c','b','a','b'};
	unsigned char ch2[] = {' ', 'a','b','c'};
	int lengch = 14;
	int lengch2 = 3;
	SString *s = new SString(ch, lengch);
	SString t;
	t.setCh(ch2);
	t.setLength(lengch2);
	cout<<s->BFindex(t, 1);

	return 0;
}
*/


/****************************************************************************
ʱ�䣺2015��10��10��11:32:00
���ߣ�cutter_point

�ļ���SqList.h

���ܣ�ʵ���ڲ�����Ĵ洢�ṹ

****************************************************************************/

#ifndef _SQLIST_H_
#define _SQLIST_H_

class SqList
{
public:
	const static int MAXSIZE = 20;
	SqList();
	~SqList();


private:
	/**
	 *  ������ݵ�����
	 *	r[0]��������
	 */
	int r[MAXSIZE + 1];

	/**
	 *  ˳���ĳ���
	 */
	int length;
};

#endif //_SQLIST_H_

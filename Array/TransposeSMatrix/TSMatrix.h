/**
*���ܣ������һ���������
*�ļ���TSMatrix.h
*ʱ�䣺2015��7��30��15:14:00
*���ߣ�cutter_point
*/


#ifndef TSMATRIX_H
#define TSMATRIX_H

#include "Triple.h"

class TSMatrix
{
	TSMatrix() {}
	TSMatrix(int u, int nu, int tu, Triple da[]);
	const static int MAXSIZE = 12500;	//�������󳤶�
	//�������캯��
	TSMatrix(const TSMatrix &t);
	//����ת�����ǵľ����ʱ�򣬰�װ�����������ת��
	TSMatrix TransposeSMatrix();
	//����ת�����ǵľ��󣬵ĵڶ��ַ������Ǿ��ǿ���ת��
	TSMatrix FastTransposeSMatrix();

	~TSMatrix();

private:
	//�������Ϣ���У��еĳ��ȣ�������Ԫ���ֵ
	int mu, nu, tu;	//�ֱ����������������ͷ���Ԫ����
	Triple data[MAXSIZE + 1]; //data��0����������
};

#endif


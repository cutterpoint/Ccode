/**
*���ܣ������һ���������,�������߼�����Ÿ��е�һ������Ԫ��λ��Ԫ��
*�ļ���RLSMatrix.cpp
*ʱ�䣺2015��7��30��17:50:42
*���ߣ�cutter_point
*/

#include "RLSMatrix.h"


RLSMatrix::RLSMatrix()
{
}

//��ʼ�����ǵ�����
RLSMatrix::RLSMatrix(int mu, int nu, int tu, int rp[], Triple da[])
{
	const int rplength = sizeof(rp) / sizeof(rp[0]);
	this->mu = mu; this->nu = nu; this->tu = tu;
	//��ʼ�����ǵ�rp,����ó��Ȱ�����0�ŵĳ��ȣ����Բ�����=
	for (int i = 1; i < rplength; ++i)
		rpos[i] = rp[i];
	//��ʼ�����ǵľ���
	for (int i = 1; i <= tu; ++i)
	{
		data[i] = da[i];
	}
}

//���ǵĿ������캯��
RLSMatrix::RLSMatrix(const RLSMatrix &rlsm)
{

}

RLSMatrix::~RLSMatrix()
{
}

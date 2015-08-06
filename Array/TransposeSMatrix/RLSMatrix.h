/**
*���ܣ������һ���������,�������߼�����Ÿ��е�һ������Ԫ��λ��Ԫ��
*�ļ���RLSMatrix.h
*ʱ�䣺2015��7��30��17:26:20
*���ߣ�cutter_point
*/

#ifndef RLSMATRIX_H
#define RLSMATRIX_H

#include "Triple.h"

class RLSMatrix
{
public:
	RLSMatrix();
	RLSMatrix(int mu, int nu, int tu, int rp[], Triple da[]);
	RLSMatrix(const RLSMatrix &rlsm);

	enum Size
	{
		MAXSIZE = 12500,  //�������󳤶�
		MAXRC = 1000
	};

	~RLSMatrix();
private:
	Triple data[MAXSIZE + 1];	//����Ԫ��Ԫ���
	int rpos[MAXRC + 1];
	int mu;		//���������
	int nu;		//���������
	int tu;		//����ķ���Ԫ�صĸ���
};


#endif /*RLSMATRIX_H*/

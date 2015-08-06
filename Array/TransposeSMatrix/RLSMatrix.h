/**
*功能：这个是一个矩阵对象,基于行逻辑，存放各行第一个非零元的位置元素
*文件：RLSMatrix.h
*时间：2015年7月30日17:26:20
*作者：cutter_point
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
		MAXSIZE = 12500,  //矩阵的最大长度
		MAXRC = 1000
	};

	~RLSMatrix();
private:
	Triple data[MAXSIZE + 1];	//非零元三元组表
	int rpos[MAXRC + 1];
	int mu;		//矩阵的行数
	int nu;		//矩阵的列数
	int tu;		//矩阵的非零元素的个数
};


#endif /*RLSMATRIX_H*/

/**
*功能：这个是一个矩阵对象
*文件：TSMatrix.h
*时间：2015年7月30日15:14:00
*作者：cutter_point
*/


#ifndef TSMATRIX_H
#define TSMATRIX_H

#include "Triple.h"

class TSMatrix
{
	TSMatrix() {}
	TSMatrix(int u, int nu, int tu, Triple da[]);
	const static int MAXSIZE = 12500;	//矩阵的最大长度
	//拷贝构造函数
	TSMatrix(const TSMatrix &t);
	//我们转置我们的矩阵的时候，安装矩阵的行序来转置
	TSMatrix TransposeSMatrix();
	//我们转置我们的矩阵，的第二种方法，那就是快速转置
	TSMatrix FastTransposeSMatrix();

	~TSMatrix();

private:
	//矩阵的信息有行，列的长度，还有三元组的值
	int mu, nu, tu;	//分别是行数，列数，和非零元个数
	Triple data[MAXSIZE + 1]; //data【0】丢弃不用
};

#endif


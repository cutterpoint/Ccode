/**
*功能：这个是一个矩阵对象,基于行逻辑，存放各行第一个非零元的位置元素
*文件：RLSMatrix.cpp
*时间：2015年7月30日17:50:42
*作者：cutter_point
*/

#include "RLSMatrix.h"


RLSMatrix::RLSMatrix()
{
}

//初始化我们的数据
RLSMatrix::RLSMatrix(int mu, int nu, int tu, int rp[], Triple da[])
{
	const int rplength = sizeof(rp) / sizeof(rp[0]);
	this->mu = mu; this->nu = nu; this->tu = tu;
	//初始化我们的rp,这里得长度包含了0号的长度，所以不能是=
	for (int i = 1; i < rplength; ++i)
		rpos[i] = rp[i];
	//初始化我们的矩阵
	for (int i = 1; i <= tu; ++i)
	{
		data[i] = da[i];
	}
}

//我们的拷贝构造函数
RLSMatrix::RLSMatrix(const RLSMatrix &rlsm)
{

}

RLSMatrix::~RLSMatrix()
{
}

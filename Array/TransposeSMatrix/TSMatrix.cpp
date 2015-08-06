/**
*功能：这个是一个矩阵对象
*文件：TSMatrix.h
*时间：2015年7月30日15:14:00
*作者：cutter_point
*/
#include <cstdio>

#include "TSMatrix.h"

//实现我们的矩阵类的声明
TSMatrix::TSMatrix(int u, int nu, int tu, Triple da[])
{
	//初始化我们的矩阵
	this->mu = u; //行
	this->nu = nu; //列
	this->tu = tu; //非零的元素
	//初始化矩阵,就是把da中的数据给到我们的data中
	for (int i = 1; i <= tu; ++i) //这个里面存放的是非零的元素数据
	{
		data[i] = da[i];
	}
}

//拷贝构造函数
TSMatrix::TSMatrix(const TSMatrix &t)
{
	this->mu = t.mu;
	this->nu = t.nu;
	this->tu = t.tu;
	//然后就是我们的数据保存
	//初始化矩阵,就是把da中的数据给到我们的data中
	for (int i = 1; i <= tu; ++i) //这个里面存放的是非零的元素数据
	{
		data[i] = t.data[i];
	}
}

/*我们转置我们的矩阵的时候,切记这个是一个算法，使用时是我们的矩阵数量远远小于行*列的大小的时候，时间复杂度是：行*元素个数
 * O(mu * tu)
 * 而我们的原始的算法是遍历行和宽，然后交换行和宽的数据，这个时间赋值度是：行*宽
 * ***************************************************************************
 * 这个算法的核心是用时间换区空间，但是时间使用也不一定多
*/
TSMatrix TSMatrix::TransposeSMatrix()
{
	TSMatrix T;
	//首先我们初始化int的数据，然后初始化我们的数组
	//新的矩阵的行是我们原来矩阵的列，列是行，个数不变
	T.mu = this->nu;	//行被赋值为列的数据
	T.nu = this->mu;	//列赋值为行
	T.tu = this->tu;	//元素个数
	//我们接着赋值我们的数组,我们的数组从头到尾赋值
	int q = 1;	//遍历我们的数组的数据
	//我们数组里面放的时候，我们一行一行地放，那么我们就得遍历行
	for (int hang = 1; hang <= this->mu; ++hang)
	{
		//我们从第一行开始，遍历我们所有的第一行的数据
		for (int p = 1; p <= this->tu; ++p)
		{
			//如果是第一行的数据，那么我们就进行赋值
			if (this->data[p].getI() == hang)
			{
				//我们存放的时候是吧行换位列，列换位行
				T.data[q].setJ(this->data[p].getI());	//设定列
				T.data[q].setI(this->data[p].getJ());	//设定行
				T.data[q].setElem(this->data[p].getElem());	//设置元素
				++q;	//移动，赋值下一个元素
			}
		}
	}

	return T;
}

/*我们转置我们的矩阵，的第二种方法，那就是快速转置
 *  O(nu + tu) 当tu 也就是零的数据很少的时候是 O（mu * nu) (就是mu * nu ≈ tu)
 * ***************************************************************************
 *  这个就是用空间换取时间的典范了
*/
TSMatrix TSMatrix::FastTransposeSMatrix()
{
	TSMatrix T;
	//首先我们初始化int的数据，然后初始化我们的数组
	//新的矩阵的行是我们原来矩阵的列，列是行，个数不变
	T.mu = this->nu;	//行被赋值为列的数据
	T.nu = this->mu;	//列赋值为行
	T.tu = this->tu;	//元素个数
	//然后我们开始转置我们的数组
	//我们用一个数组来保存我们原始矩阵的每一列的非零元素，也就是我们的不同数据，有用的个数
	int num[MAXSIZE] = { 0 };//初始化
	//我们还需要一个数据，来表示原始数据的没列的数据在转置矩阵数组中的起始位置
	int cpot[MAXSIZE] = { 0 };//初始化
	//我们求每一列的个数,遍历我们的原始矩阵
	for (int i = 1; i <= this->tu; ++i)
	{
		//为我们的数组赋值,这个一个列的数据都++
		++(num[this->data[i].getJ()]);
	}
	cpot[1] = 1;	//原始矩阵的第一列的第一个数据在转置之后的开始的位置就是第一个
	//我们求每列非零值在数组中的序列
	for (int col = 2; col <= this->nu; ++col) //有多少列就有多少个值
	{
		//当前列的起始位置是
		cpot[col] = cpot[col - 1] + num[col - 1];
	}
	//给我们的数组赋值
	for (int p = 1; p < this->tu; ++p)
	{
		//依次得到我们当前数组的列的数据
		int lie = this->data[p].getJ();
		//根据这个数据的列，我们得到我们的相应的列在新矩阵的位置
		int q = cpot[lie]; //列的起始位置，我们在当前列存放一个数据，那么下次就要在下一个位置开始
		T.data[q].setI(this->data[p].getJ());		//设置这个数据的行,列，值
		T.data[q].setJ(this->data[p].getI());
		T.data[q].setElem(this->data[p].getElem());
		//我们把这个列的初始位置+1
		++(cpot[lie]);
	}

	//返回我们的矩阵
	return T;
}

TSMatrix::~TSMatrix()
{
	printf("TSMatrix析构函数得到调用");
}

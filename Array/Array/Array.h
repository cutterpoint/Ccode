/*
*功能：数组的顺序存储表示和实现
*时间：2015年7月29日16:26:48
*文件：Array.h
*作者：cutter_point
*/


#ifndef __Array__
#define __Array__

/**
 * 我们的数组的顺序存储表示和实现 
 */
class Array
{
private:
	int *base;	//我们数组元素的起始地址
	int dim;	//数组的维度
	int *bounds;	//数组维界基址
	int *constants;	//数组映像函数常量基址
};

#endif	/* defined(_Array_) */


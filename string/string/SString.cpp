/*
*功能：这个是定长的串的顺序存储
*时间：2015年7月15日17:16:01
*文件：SString.h
*作者：cutter_point
*/

#include "SString.h"

//得到这个字符串的长度
//int length(); 我们不知道这个数组的终止条件是不能求出来这个数组有多长的
/*
int SString::length()
{
	return 0;
}
*/

//得到这个字符串的长度
//int getLength();
unsigned int SString::getLength()
{
	return this->length;
}

//获取我们的字符串
//char* getCh();
unsigned char* SString::getCh()
{
	return this->ch;
}


//一个匹配子串的算法实现
/************************************************************************/
/*
返回子串T在主串S中第pos位置之后的位置，若不存在，返回0
*/
/************************************************************************/
//int BFindex(SString T, int pos);
int SString::BFindex(SString T, int pos)
{
	//首先我们用两个游标参数来计数我们遍历的位置
	int i = pos, j = 1;

	//然后我们用两个unsigned char 的指针来指向两个我们来比较的字符串
	unsigned char *p1 = this->getCh(), *p2 = T.getCh();
	//开始循环比较，当第一个匹配到了的时候，我们就接着比较后面的，如果中间出错，那么我们回头从新比较主串的下一个元素作为开始
	//记住我么的字符串的第一个元素时不存放东西的，我们从下标为1的那个开始存放包括1
	while (i <= this->getLength() && j <= T.getLength())
	{
		//如果匹配到了我们就一起匹配第二个元素
		if (p1[i] == p2[j])
		{
			++i;
			++j;
		}
		else
		{
			//否则我们就回到起点的第二个元素和子串进行比较
			i = i - j + 2;	//下一个元素
			j = 1;	//子串从头开始
		}
	}

	//最后看看是不是有完全匹配到的
	if (j > T.getLength())
		return i - T.getLength();	//获取这个位置的地方
	else
		return 0;
}
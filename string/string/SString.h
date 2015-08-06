/*
*功能：这个是定长的串的顺序存储
*时间：2015年7月15日17:16:01
*文件：SString.h
*作者：cutter_point
*/

#ifndef SSTRING_H
#define SSTRING_H

#define MAXSTRLEN 255

class SString
{
	unsigned char* ch;	//我们的串的顺序存储空间
	unsigned int length; //我们有效元素的个数
public:
	SString(){}
	SString(unsigned char c[], int lenth){ ch = new unsigned char[MAXSTRLEN + 1]; ch = c; this->length = lenth; }	//申请堆存储空间
	//一个匹配子串的算法实现
	/************************************************************************/
	/*
	返回子串T在主串S中第pos位置之后的位置，若不存在，返回0
	*/
	/************************************************************************/
	int BFindex(SString T, int pos);
	//得到这个字符串的长度
	unsigned int getLength();
	unsigned char* getCh();
	//设置相应的值
	void setCh(unsigned char *c) { ch = c; }
	void setLength(unsigned int len) { length = len; }
	//unsigned char* getCh() { return ch; }
	//unsigned int getLength() { return length; }
};


#endif



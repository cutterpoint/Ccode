/*
*���ܣ�����Ƕ����Ĵ���˳��洢
*ʱ�䣺2015��7��15��17:16:01
*�ļ���SString.h
*���ߣ�cutter_point
*/

#ifndef SSTRING_H
#define SSTRING_H

#define MAXSTRLEN 255

class SString
{
	unsigned char* ch;	//���ǵĴ���˳��洢�ռ�
	unsigned int length; //������ЧԪ�صĸ���
public:
	SString(){}
	SString(unsigned char c[], int lenth){ ch = new unsigned char[MAXSTRLEN + 1]; ch = c; this->length = lenth; }	//����Ѵ洢�ռ�
	//һ��ƥ���Ӵ����㷨ʵ��
	/************************************************************************/
	/*
	�����Ӵ�T������S�е�posλ��֮���λ�ã��������ڣ�����0
	*/
	/************************************************************************/
	int BFindex(SString T, int pos);
	//�õ�����ַ����ĳ���
	unsigned int getLength();
	unsigned char* getCh();
	//������Ӧ��ֵ
	void setCh(unsigned char *c) { ch = c; }
	void setLength(unsigned int len) { length = len; }
	//unsigned char* getCh() { return ch; }
	//unsigned int getLength() { return length; }
};


#endif



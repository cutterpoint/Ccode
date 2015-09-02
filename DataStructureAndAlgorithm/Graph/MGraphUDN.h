/****************************************************************************
ʱ�䣺2015��8��31��17:23:44
���ߣ�cutter_point

�ļ���MGraph.h

���ܣ�ʵ�����ǵĸ���ͼ�Ĳ���

****************************************************************************/

#ifndef _MGRAPHUDN_H_
#define _MGRAPHUDN_H_

#include <fstream>
#include <string>
#include <iostream>

//���ǵ���������
class MGraphUDN
{
public:
	static const int MAX_VERTEX_NUM = 26;	//����ͼ����ඥ�����
	MGraphUDN();
	~MGraphUDN();

private:
	char vexs[MAX_VERTEX_NUM];	//��Ŷ���
	int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//��ž�������
	int vexnum;	//�������
	int arcnum;		//���ĸ�����Ҳ��������ͼ�ı���

	//������һ��������ȷ��������������λ��
	int locateVex(char u);
	//���ļ��ж�ȡ���ݳ�ʼ�����ǵĳ�Ա����
	void initData(std::string filename);
	//�õ����ǣ��ָ��λ��
	int getIndexOfFlag(char *begin, char *end, char flag);
};

#endif //_MGRAPHUDN_H_
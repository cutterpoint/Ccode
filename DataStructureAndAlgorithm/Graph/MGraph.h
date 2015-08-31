/****************************************************************************
ʱ�䣺2015��8��31��17:23:44
���ߣ�cutter_point

�ļ���MGraph.h

���ܣ�ʵ�����ǵĸ���ͼ�Ĳ���

****************************************************************************/

#ifndef _MGRAPH_H_
#define _MGRAPH_H_

#include <fstream>
#include <string>
#include <iostream>

class MGraph
{
public:
	static const int MAX_VERTEX_NUM = 26;	//����ͼ����ඥ�����
	MGraph();
	~MGraph();

private:
	char vexs[MAX_VERTEX_NUM];	//��Ŷ���
	int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//��ž�������
	int vexnum;	//�������
	int arcnum;		//���ĸ�����Ҳ��������ͼ�ı���
};

#endif //_MGRAPH_H_
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
	static const int MAX_MAXTRIX_NUM = INT_MAX;
	MGraphUDN();
	~MGraphUDN();
	MGraphUDN(std::string filename);

	/**
	 *  �������ǵ��ڽӾ���
	 */
	void createUDN();

	/**
	 * �������
	 */
	void printMaxtrix();

private:
	std::string vexs[MAX_VERTEX_NUM];	//��Ŷ���
	int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//��ž�������
	int vexnum;	//�������
	int arcnum;		//���ĸ�����Ҳ��������ͼ�ı���
	std::string filename;	//������Դ�ļ���

	/**
	 * ������һ��������ȷ��������������λ��
	 */
	int locateVex(std::string u);

	/**
	 * ���ļ��ж�ȡ���ݳ�ʼ�����ǵĳ�Ա����
	 */
	void initData(std::string filename);

	/**
	 * �õ����ǣ��ָ��λ��
	 */
	int getIndexOfFlag(char *begin, char *end, char flag);

	/**
	 * ��ʼ�����ǵ�������������
	 * ��ʼ�� ���㣬 �� ��������Ҳ����int vexnum  int arcnum
	 */
	void initNum(char *buf, int splitindex, int length);

	/**
	 * ��ʼ�����ǵ�string vexs[MAX_VERTEX_NUM]��Ҳ���ǳ�ʼ�����ǵĶ�������
	 */
	void initVexs(char *buf, char flag, int length);

	/**
	 * ��ʼ�����ǵ��ڽӾ�����Ҫ�Ĳ���
	 */
	void initvvw(char *buf, int length);

	/**
	 * ��ʼ�����ǵ��ڽӾ���
	 */
	void initMatrix(std::string v1, std::string v2, int weight);
};

#endif //_MGRAPHUDN_H_
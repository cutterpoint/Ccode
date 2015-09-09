/****************************************************************************
ʱ�䣺2015��9��6��15:15:01
���ߣ�cutter_point

�ļ���MGraphDG.h

���ܣ�ʵ�����ǵ�����ͼ�Ĺ���������ʮ������洢��ʾ

****************************************************************************/

#ifndef _MGRAPHDG_H_
#define _MGRAPHDG_H_

#include <string>
#include <fstream>

class ArcBox;	//���ǵĻ��ڵ���

//����ڵ�
class VexNode
{
	friend class MGraphDG;
public:
	VexNode(){}
	~VexNode();
private:
	/**
	 *  �ڵ���Ϣ�������ýڵ�������
	 */
	std::string nodeName;

	/**
	 *  �ֱ�ָ��һ���뻡�ͳ���
	 */
	ArcBox *firstin, *firstout;
};

//���ǵĻ��ڵ���
class ArcBox
{
	friend class MGraphDG;
public:
	ArcBox(){}
	~ArcBox();
private:
	/**
	 *  ָ��û���β��ͷ�����λ��
	 */
	int tailvex, headvex;

	/**
	 *  �ֱ��ǻ�ͷ��ͬ�ͻ�β��ͬ�Ļ�������
	 */
	ArcBox *hlink, *tlink;

	/**
	 *  ������Ϣ������Ȩֵ�ȵȣ��������ǿ����趨һ���ַ�����������Ϣ
	 */
	std::string info;
};

//ʮ������洢��ʾ,���ǵ�����ͼ
class MGraphDG
{
public:
	/**
	 *  ���������
	 */
	static const int MAX_VERTEX_NUM = 26;
	MGraphDG();
	~MGraphDG();
private:

	/**
	 *  ���Ƕ��������
	 */
	VexNode xlist[MAX_VERTEX_NUM];
	
	/**
	 *  ����ͼ�Ķ�����������
	 */
	int vexnum, arcnum;

	/**
	 *  ��ȡ�ļ�
	 */
	void readFile(std::string filename);

	/**
	 *  ��ʼ�����ǵ����ݳ�Ա���������ͻ���
	 */
	void intiVAnum(std::string line);

	/**
	 *  ��ʼ�����ǵĶ�������
	 */
	void initXlist(std::string line);

	/**
	 *  ��ʼ�����Ǹ�������ʮ������
	 */
	void initLink(std::string line);

	/**
	 *  �õ����ǵ������������е�λ��
	 */
	int locateVex(std::string name);
};



#endif //_MGRAPHDG_H_
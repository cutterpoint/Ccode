/****************************************************************************
ʱ�䣺2015��9��6��15:15:01
���ߣ�cutter_point

�ļ���MGraphDG.cpp

���ܣ�ʵ�����ǵ�����ͼ�Ĺ���������ʮ������洢��ʾ

****************************************************************************/

#include "stdafx.h"
#include "MGraphDG.h"

#include <sstream>

/////////////////////////////////////////////////////////////////////////////
////////////////////////////���ǵĶ���ڵ��������///////////////////////////////
VexNode::~VexNode()
{
	delete firstin;
	delete firstout;
}


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////���ǵĻ��ڵ��������////////////////////////////////
ArcBox::~ArcBox()
{
	delete hlink, tlink;
}


/////////////////////////////////////////////////////////////////////////////
///////////////////���ǵ�ʮ������洢��ʾ,���ǵ�����ͼ�������///////////////////////
MGraphDG::MGraphDG()
{

}


MGraphDG::~MGraphDG()
{
	delete[] xlist;
}

/**
 *  ��ȡ�ļ�
 */
void MGraphDG::readFile(std::string filename)
{
	std::ifstream in(filename);
	std::string line;	//һ������
	int num = 0;	//���ǵ�����

	if (in.is_open())
	{
		while (std::getline(in, line, '\n'))
		{
			if (num == 0)
			{
				//��ʼ������������ͻ��ĸ���
				this->intiVAnum(line);
				++num;
			}//if
			else if (num == 1)
			{
				//��ʼ�������ǵĶ�����������
				++num;
			}//else if
			else
			{
				//��ʼ�����ǵ�ʮ������

				++num;
			}
		}//while
		//�ر��ļ���
		in.clear();
		in.close();
	}
}

/**
 *  ��ʼ�����ǵ����ݳ�Ա���������ͻ���
 * ��ʽ��4 7
 */
void MGraphDG::intiVAnum(std::string line)
{
	std::stringstream sstr(line);	//���������Ժܺõش���string����
	std::string num1, num2;
	sstr >> num1 >> num2;	//��ȡ�������ֵ��ַ���
	this->vexnum = atoi(num1.c_str());
	this->arcnum = atoi(num2.c_str());
}

/**
*  ��ʼ�����ǵĶ�������
*/
void initXlist(std::string line);

/**
*  ��ʼ�����Ǹ�������ʮ������
*/
void initLink(std::string line);

/****************************************************************************
ʱ�䣺2015��10��9��10:32:36
���ߣ�cutter_point

�ļ���BTNode.h

���ܣ�B-�������ݽṹ

****************************************************************************/
#ifndef _BTNODE_H_
#define _BTNODE_H_

class BTNode
{
	friend class BTree;
public:
	const static int m = 3;
	BTNode();
	~BTNode();

private:
	/**
	 *  ����йؼ��ָ���
	 */
	int keynum;

	/**
	 *  ָ��˫�׽ڵ�
	 */
	BTNode *parent;

	/**
	 *  �ؼ���������Ҳ�������ǵ���������
	 */
	int key[m + 1];

	/**
	 *  ����ָ������
	 */
	BTNode *ptr[m + 1];
};

//����һ���࣬����������ǲ��ҵ��Ľڵ����Ϣ
class Result
{
public:
	/**
	 *  ���캯��
	 */
	Result(BTNode *node, int ii, int t)
	{
		this->pt = node;
		this->i = ii;
		this->tag = t;
	}

	Result(){}

	/**
	 *  ָ���ҵ��Ľڵ�
	 */
	BTNode *pt;

	/**
	 *  1...m���ڽڵ��еĹؼ��ֵ����,�±�
	 */
	int i;

	/**
	 * ���ҳɹ�1,ʧ��0
	 */
	int tag;
};

#endif //_BTNODE_H_


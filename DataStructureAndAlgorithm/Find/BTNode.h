/****************************************************************************
时间：2015年10月9日10:32:36
作者：cutter_point

文件：BTNode.h

功能：B-树的数据结构

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
	 *  结点中关键字个数
	 */
	int keynum;

	/**
	 *  指向双亲节点
	 */
	BTNode *parent;

	/**
	 *  关键字向量，也就是我们的数据数组
	 */
	int key[m + 1];

	/**
	 *  子树指针向量
	 */
	BTNode *ptr[m + 1];
};

//定义一个类，用来存放我们查找到的节点的信息
class Result
{
public:
	/**
	 *  构造函数
	 */
	Result(BTNode *node, int ii, int t)
	{
		this->pt = node;
		this->i = ii;
		this->tag = t;
	}

	Result(){}

	/**
	 *  指向找到的节点
	 */
	BTNode *pt;

	/**
	 *  1...m，在节点中的关键字的序号,下标
	 */
	int i;

	/**
	 * 查找成功1,失败0
	 */
	int tag;
};

#endif //_BTNODE_H_


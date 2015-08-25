/****************************************************************************
时间：2015年8月24日17:13:47
作者：cutter_point

文件：BiThrNode.h

功能：实现我们的线索二叉树

****************************************************************************/
#ifndef _Tree_BITHRNODE_
#define _Tree_BITHRNODE_

class BiThr;

class BiThrNode
{
	friend class BiThr;
public:
	/**
	*这个枚举是为了辨别是指向一个孩子节点，还是指向这个节点的前驱或后继
	*/
	enum PointerTag
	{
		Link,
		Thread
	};

	BiThrNode();
	~BiThrNode();

private:
	char data;
	BiThrNode *lchild, *rchild;
	PointerTag LTag, RTag;
};

#endif	/*#define _Tree_BITHRNODE_*/


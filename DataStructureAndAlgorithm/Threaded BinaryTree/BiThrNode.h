/****************************************************************************
ʱ�䣺2015��8��24��17:13:47
���ߣ�cutter_point

�ļ���BiThrNode.h

���ܣ�ʵ�����ǵ�����������

****************************************************************************/
#ifndef _Tree_BITHRNODE_
#define _Tree_BITHRNODE_

class BiThr;

class BiThrNode
{
	friend class BiThr;
public:
	/**
	*���ö����Ϊ�˱����ָ��һ�����ӽڵ㣬����ָ������ڵ��ǰ������
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


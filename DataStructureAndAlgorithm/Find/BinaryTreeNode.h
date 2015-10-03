/****************************************************************************
时间：2015年10月3日19:33:32
作者：cutter_point

文件：BinaryTreeNode.h

功能：实现我们二叉树节点

****************************************************************************/
class BinaryTreeNode
{
	friend class BinarySortTree;
public:
	BinaryTreeNode();
	~BinaryTreeNode();
private:
	int data;
	BinaryTreeNode *lchild, *rchild;	//左右孩子
};


/****************************************************************************
ʱ�䣺2015��10��3��19:33:32
���ߣ�cutter_point

�ļ���BinaryTreeNode.h

���ܣ�ʵ�����Ƕ������ڵ�

****************************************************************************/
class BinaryTreeNode
{
	friend class BinarySortTree;
public:
	BinaryTreeNode();
	~BinaryTreeNode();
private:
	int data;
	BinaryTreeNode *lchild, *rchild;	//���Һ���
};


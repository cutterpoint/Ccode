/****************************************************************************
ʱ�䣺2015��8��28��16:41:21
���ߣ�cutter_point

�ļ���HuffmanTree.h

���ܣ�ʵ�����ǵĹ���������

****************************************************************************/

#ifndef _HUFFMAN_TREE_H_
#define _HUFFMAN_TREE_H_

class HuffmanTree;

class HuffmanNode
{
	friend class HuffmanTree;
public:
	HuffmanNode(){ weight = 0; parent = 0; lchild = 0; rchild = 0; }
	~HuffmanNode(){}
private:
	unsigned int weight;
	unsigned int parent, lchild, rchild;
};

class HuffmanTree
{
public:
	HuffmanTree();
	~HuffmanTree();

	/**
	 * ��ʼ�����ǵĹ��������������������Ա�Ĺ�������
	 * @param int *w ���ǵ�Ȩ������
	 * @param int n �����������ݵĸ���
	 */
	void huffmanInit(int *w, int n);

private:
	/**
	 * �����ά���飬������Ź���������
	 */
	char **huffmanCode;

	/**
	 * ��Ź�������������,0��λ����Ŷ���
	 */
	HuffmanNode *huffmanTree;

	/**
	 * �ڹ��������в��ҵ���С������������������������parentΪ0
	 */
	void select(int start, int end, int *s1, int *s2);
};

#endif /*_HUFFMAN_TREE_H_*/
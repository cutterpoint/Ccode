/****************************************************************************
时间：2015年8月28日16:41:21
作者：cutter_point

文件：HuffmanTree.h

功能：实现我们的哈夫曼编码

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
	 * 初始化我们的哈夫曼树，建立基于线性表的哈夫曼树
	 * @param int *w 我们的权重数组
	 * @param int n 我们数组数据的个数
	 */
	void huffmanInit(int *w, int n);

private:
	/**
	 * 定义二维数组，用来存放哈夫曼编码
	 */
	char **huffmanCode;

	/**
	 * 存放哈夫曼树的数组,0号位不存放东西
	 */
	HuffmanNode *huffmanTree;

	/**
	 * 在哈夫曼树中查找到最小的两个数，并且这两个数的parent为0
	 */
	void select(int start, int end, int *s1, int *s2);
};

#endif /*_HUFFMAN_TREE_H_*/
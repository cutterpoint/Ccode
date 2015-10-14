/****************************************************************************
时间：2015年10月14日09:54:50
作者：cutter_point

文件：HashTable.h

功能：哈希表的构建

****************************************************************************/
#ifndef _HASH_TABLE_H_
#define _HASH_TABLE_H_

class Data
{
	friend class HashTable;
public:
	Data();
	Data(int length, int count = 0);
	~Data();
	
private:
	/**
	 *  数据元素存放基址，动态分配数组
	 */
	int *elem;

	/**
	 *  当前数据元素的个数
	 */
	int count;

	/**
	 *  数组的长度
	 */
	int sizeindex;
};

class HashTable
{
	friend class Data;
public:
	HashTable();
	~HashTable();

	/**
	 *  得到我们的哈希表的查找到的位置，或者下一个插入的位置
	 *  k是查找的数据
	 *	c计算冲突的次数
	 */
	int searchHash(int k, int &c);
private:
	/**
	 *  哈希表的数据存放类
	 */
	Data *h;

	/**
	 *   判断查找是否成功
	 *	找到了数据位置 这个是1
	 *	没有找到，但是找到了插入的位置返回0
	 */
	int search_OK;

	/**
	 *  哈希函数
	 */
	int hash(int k);

	/**
	 *  线性探测在散列
	 */
	int collision(int p, int c);
};

#endif //_HASH_TABLE_H_
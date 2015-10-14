/****************************************************************************
ʱ�䣺2015��10��14��09:54:50
���ߣ�cutter_point

�ļ���HashTable.h

���ܣ���ϣ��Ĺ���

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
	 *  ����Ԫ�ش�Ż�ַ����̬��������
	 */
	int *elem;

	/**
	 *  ��ǰ����Ԫ�صĸ���
	 */
	int count;

	/**
	 *  ����ĳ���
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
	 *  �õ����ǵĹ�ϣ��Ĳ��ҵ���λ�ã�������һ�������λ��
	 *  k�ǲ��ҵ�����
	 *	c�����ͻ�Ĵ���
	 */
	int searchHash(int k, int &c);
private:
	/**
	 *  ��ϣ������ݴ����
	 */
	Data *h;

	/**
	 *   �жϲ����Ƿ�ɹ�
	 *	�ҵ�������λ�� �����1
	 *	û���ҵ��������ҵ��˲����λ�÷���0
	 */
	int search_OK;

	/**
	 *  ��ϣ����
	 */
	int hash(int k);

	/**
	 *  ����̽����ɢ��
	 */
	int collision(int p, int c);
};

#endif //_HASH_TABLE_H_
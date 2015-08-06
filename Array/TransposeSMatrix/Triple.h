/**
 *���ܣ������һ����Ԫ��Ľṹ
 *�ļ���Triple.h
 *ʱ�䣺2015��7��30��15:00:07
 *���ߣ�cutter_point
*/

#ifndef TRIPLE_H
#define TRIPLE_H

class Triple
{
public:
	Triple() {}
	Triple(int i, int j, int elem) : i(i), j(j), elem(elem) {}

	/*���ǵ�set��get����*/
	void setI(int i) { this->i = i; }
	void setJ(int j) { this->j = j; }
	void setElem(int e) { this->elem = e; }
	int getI() { return i; }
	int getJ() { return j; }
	int getElem() { return elem; }

private:
	int i, j, elem;	//�ֱ��������������������i��j�е�ֵelem
};

#endif	TRIPLE_H

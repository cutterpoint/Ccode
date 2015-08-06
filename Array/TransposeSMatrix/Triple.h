/**
 *功能：这个是一个三元组的结构
 *文件：Triple.h
 *时间：2015年7月30日15:00:07
 *作者：cutter_point
*/

#ifndef TRIPLE_H
#define TRIPLE_H

class Triple
{
public:
	Triple() {}
	Triple(int i, int j, int elem) : i(i), j(j), elem(elem) {}

	/*我们的set和get方法*/
	void setI(int i) { this->i = i; }
	void setJ(int j) { this->j = j; }
	void setElem(int e) { this->elem = e; }
	int getI() { return i; }
	int getJ() { return j; }
	int getElem() { return elem; }

private:
	int i, j, elem;	//分别代表矩阵的行数，列数，i行j列的值elem
};

#endif	TRIPLE_H

#ifndef _SolutionOfEquations_H_

#define _SolutionOfEquations_H_

#include "SQUARE_MATRIX.H"

#include <string>

#include <string>

class DBL_STR
{
public:
	string result;
	double value;
};

class SolutionOfEquations : public virtual MATRIX
{
public:
	SolutionOfEquations(int equations = 1);//���������չ����
	SolutionOfEquations(const SolutionOfEquations &x);//�������캯��
	SolutionOfEquations(const MATRIX &x);//������ת��Ϊ������Ŀ������캯��
	~SolutionOfEquations();
	void ShowSolutions()const;//��ʾ���̵Ľ�
	SolutionOfEquations& operator = (const SolutionOfEquations &x);//��ֵ����
protected:
	DBL_STR *a;
private:
	static DBL_STR AnalyseValue(double x1, double x2);//����ֵ���޽⣬������
	void Cramer()const;//����Ĭ����
	void OutputDBL_STR(DBL_STR)const;//��ӡ�����Ľ��
};

	


#endif
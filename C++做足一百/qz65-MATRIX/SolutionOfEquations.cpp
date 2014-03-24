#include <iostream>

using namespace std;

#include "SolutionOfEquations.H"


SolutionOfEquations::SolutionOfEquations(int equations)
{
	if(equations < 1) row = 1;
	this->row = equations, this->colume = equations + 1;
	this->matrix = new double[this->row * this->colume];
	a = new DBL_STR[this->row];
	for(int i = 0; i < this->row * this->colume; i ++) matrix[i] = 0;
}

SolutionOfEquations::SolutionOfEquations(const SolutionOfEquations &x):MATRIX(x)
{
}

SolutionOfEquations::SolutionOfEquations(const MATRIX &x)
{
	int i, j;
	if(x.Colume() != x.Row() + 1) 
	{
		cout << "此矩阵不是方程组的扩展矩阵!" << endl;
		exit(1);
	}
	else
	{
		this->colume = x.Colume(); this->row = x.Row();
		this->matrix = new double[this->row * this->colume];
		a = new DBL_STR[this->row];
		for(i = 0; i < this->row; i ++)
		{
			for(j = 0; j < this->colume; j ++)
			{
				this->matrix[i * this->colume + j] = x(i + 1, j + 1);
			}
		}
	}
}



SolutionOfEquations::~SolutionOfEquations()
{
	delete []a;
}

SolutionOfEquations& SolutionOfEquations::operator = (const SolutionOfEquations &x)
{
	if(this->row != x.row)
	{
		this->row = x.row;
		this->colume = x.colume;
		delete []this->matrix;
		this->matrix = new double[x.row * x.colume];
		delete []this->a;
		this->a = new DBL_STR[x.row];
	}
	for(int i = 0; i < x.row * x.colume; i ++)
	{
		this->matrix[i] = x.matrix[i];
	}
	return (*this);
}
	

void SolutionOfEquations::Cramer()const
{
	double *value;
	int i;
	value = new double[this->colume];
	SQUARE_MATRIX x;
	SolutionOfEquations y;
	if(this->row == 1) value[1] = matrix[1], value[0] = matrix[0];
	if(this->row >= 2)
	{
		for(i = 0; i < this->colume; i ++)
		{
			y = this->Columes_Exchange(i, this->colume);
			x = y.Erase_Colume(this->colume);
			value[i] = x.Determinant();
			cout << value[i] << endl;
		}
	}
	for(i = 1; i < this->colume; i ++)
	{
		this->a[i - 1] = AnalyseValue(value[i], value[0]);
	}
}

DBL_STR SolutionOfEquations::AnalyseValue(double x1, double x2)
{
	DBL_STR a;
	if(!x1 && !x2) a.result = "无穷解";
	else if(x1 && !x2) a.result = "无解";
	else a.value = x1 / x2;
	return a;
}

void SolutionOfEquations::ShowSolutions()const
{
	this->Cramer();
	cout << "你要解的方程的扩展矩阵为:" << endl;
	this->Output(); cout << endl;
	for(int i = 0; i < this->row; i ++)
	{
		cout << "ROOT" << '[' << i + 1 << ']' << ": ";
		this->OutputDBL_STR(a[i]);
		cout << endl;
	}
}

void SolutionOfEquations::OutputDBL_STR(DBL_STR x)const
{
	if(x.result[0] == '\0') cout << x.value;
	else cout << x.result;
}

int main()
{
	SolutionOfEquations a(4);
	a.Input();
	a.Output(); cout << endl;
	a.ShowSolutions();
	return 0;
}

/*int main()
{
	MATRIX a(3, 4), b(3, 4);
	SolutionOfEquations c;
	cin >> a >> b;
	cout << a << endl << b << endl;
	c = a + b;
	cout << c << endl;
	return 0;
}*/


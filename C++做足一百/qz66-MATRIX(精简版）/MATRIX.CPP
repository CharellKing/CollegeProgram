#include <iostream>
#include <iomanip>
using namespace std;
#include "MATRIX.H"

MATRIX::MATRIX(int row, int colume): row(row), colume(colume)
{
	if (row <= 0 || colume <= 0 || row <= 1 && colume <= 1)
	{
		cout << "Incorrect parameters\n";
		exit(1);
	}
	this->matrix = new double [row * colume];
	for(int i = 0; i < row * colume; i ++) this->matrix[i] = 0;
}

MATRIX::MATRIX(const MATRIX& x): row(x.row), colume(x.colume)
{
	this->matrix = new double[row * colume];
	for(int i = 0; i < row * colume; i ++) this->matrix[i] = x.matrix[i];
}

MATRIX::~MATRIX()
{
	delete [] matrix;
}
	
void MATRIX::Input()
{
	double x;
	int k = 0;
	cin.sync();
	do
	{
		if(cin >> x)
		{
			matrix[k ++] = x;
		}
		else
		{
			cin.clear();
			cin.sync();
			k = 0;
			cout << "不正确的输入，请重新输入!" << endl;
		}
	}
	while(k < row * colume);
	cin.sync();
}

istream& operator >>(istream& in, MATRIX& y)
{
	double x;
	int k = 0;
	cin.sync();
	do
	{
		if(cin >> x)
		{
			y.matrix[k ++] = x;
		}
		else
		{
			cin.clear();
			cin.sync();
			delete [] y.matrix;
			y.matrix = new double[y.row * y.colume];
			k = 0;
			cout << "不正确的输入，请重新输入!" << endl;
		}
	}
	while(k != y.row * y.colume);
	return in;
}

	
void MATRIX::Output() const
{
	int i, j;
	cout << fixed << setprecision(2);
	for(i = 1; i <= row; i ++)
	{
		for(j = 1; j <= colume; j ++)
		{
			cout << setw(5) << (*this)(i, j) << ' ';
		}
		cout << endl;
	}
}

ostream& operator <<(ostream& out, const MATRIX &x)
{
	int i, j;
	cout << endl;
	for(i = 0; i < x.row; i ++)
	{
		for(j = 0; j < x.colume; j ++)
		{
			cout << setw(6) << x.matrix[i * x.colume + j] << ' ';
		}
		cout << endl;
	}
	return out;
}

void MATRIX::Add(const MATRIX &x, const MATRIX &y)
{
	int i, j;
	if (y.row != x.row || y.colume != x.colume)
	{
		cout << "两个矩阵不能相加!" << endl;
		exit(1);
	}
	if (row != x.row || colume != x.colume)
	{
		row = x.row;
		colume = x.colume;
		delete [] matrix;
		matrix = new double [row * colume];
	}
	for (i = 1; i <= row; i ++)
	{
		for (j = 1; j <= colume; j ++)
		{
			(*this)(i, j) = y(i, j) + x(i, j);
		}
	}
}

MATRIX MATRIX::operator +(const MATRIX &x)const
{
	MATRIX y(row, colume);
	y.Add(*this, x);
	return y;
}


void MATRIX::Sub(const MATRIX &x, const MATRIX &y)
{
	int i, j;
	if (y.row != x.row || y.colume != x.colume)
	{
		cout << "两个矩阵不能相减!" << endl;
		exit(1);
	}
	if (row != x.row || colume != x.colume)
	{
		row = x.row;
		colume = x.colume;
		delete [] matrix;
		matrix = new double [row * colume];
	}
	for (i = 1; i <= row; i ++)
	{
		for (j = 1; j <= colume; j ++)
		{
			(*this)(i, j) = x(i, j) - y(i, j);
		}
	}
}


MATRIX MATRIX::operator -(const MATRIX &x)const
{
	MATRIX y(x.row, x.colume);
	y.Sub(*this, x);
	return y;
}


MATRIX& MATRIX::operator +=(const MATRIX &x)
{
	int i;
	if(row != x.row || colume != x.colume)
	{
		cout << "此矩阵不能追加!" << endl;
		exit(1);
	}
	else
	{
		for(i = 0; i < row * colume; i ++) this->matrix[i] += x.matrix[i];
	}
	return (*this);
}

MATRIX& MATRIX::operator -=(const MATRIX &x)
{
	MATRIX y;
	int i;
	if(row != x.row || colume != x.colume)
	{
		cout << "此矩阵不能追减!" << endl;
		exit(1);
	}
	else
	{
		for(i = 0; i < row * colume; i ++) this->matrix[i] -= x.matrix[i];
	}
	return (*this);
}


const MATRIX& MATRIX::operator =(const MATRIX &x)
{
	if(*this != x)
	{
		if(row != x.row || colume != x.colume)
		{
			row = x.row;
			colume = x.colume;
			delete [] matrix;
			matrix = new double [row * colume];
		}
		for(int i = 0; i < row * colume; i ++) this->matrix[i] = x.matrix[i];
	}
	return *this;
}


bool MATRIX::operator ==(const MATRIX &x)const
{
	if(this->colume != x.colume || this->row != x.row) return false;
	for(int i = 0; i < x.colume * x.row; i ++)
	{
		if(x.matrix[i] != this->matrix[i]) return false;
	}
	return true;
}

bool MATRIX::operator !=(const MATRIX &x)const
{
	return !((*this) == x);
}

void MATRIX::NegativeSign(const MATRIX &x)
{
	if(row != x.row || colume != x.colume)
	{
		row = x.row;
		colume = x.colume;
		delete [] matrix;
		matrix = new double [row * colume];
	}
	for(int i = 0; i < row * colume; i ++)
	{
		matrix[i] = -x.matrix[i];
	}
}

MATRIX MATRIX::operator -()const
{
	MATRIX x(row, colume);
	x.NegativeSign(*this);
	return x;
}

void MATRIX::Mul(const MATRIX &x, const MATRIX &y)
{
	int i, j, k, m;
	if(x.colume != y.row)
	{
		cout << "两矩阵不能相乘!" << endl;
		exit(1);
	}
	if(row != x.row || colume != y.colume)
	{
		row = x.row;
		colume = y.colume;
		delete [] matrix;
		matrix = new double [row * colume];
	}
	for(i = 0; i < row * colume; i ++) matrix[i] = 0;
	k = 0;
	for(i = 1; i <= x.row; i ++)
	{
		for(m = 1; m <= y.colume; m ++)
		{
			for(j = 1; j <= x.colume; j ++)
			{
					matrix[k] += (x(i, j) * y(j, m));
			}
			k ++;
		}
	}
}
	
MATRIX MATRIX::operator *(const MATRIX &x)const
{
	MATRIX y(row, x.colume);
	y.Output(); cout << endl;
	y.Mul(x, *this);
	return y;
}

MATRIX& MATRIX::operator *=(const MATRIX &x)
{
	MATRIX y(this->row, x.colume);
	if(this->colume != x.row)
	{
		cout << "此矩阵不能追乘!" << endl;
		exit(1);
	}
	else
	{
		y = (*this) * x;
	}
	(*this) = y;
	return *this;
}


void MATRIX::Mul(const MATRIX &x, double y)
{
	if(row != x.row || colume != x.colume)
	{
		row = x.row;
		colume = x.colume;
		delete [] matrix;
		matrix = new double [row * colume];
	}
	for(int i = 0; i < row * colume; i ++)
	{
		matrix[i] = x.matrix[i] * y;
	}
}

	
MATRIX MATRIX::operator *(double x)const
{
	MATRIX y(row, colume);
	y.Mul(*this, x);
	return y;
}

MATRIX operator *(double x, const MATRIX& y)
{
	return MATRIX(y * x);
}

void MATRIX::Transpose_Matrix(const MATRIX &x)
{
	int i, j;
	if(row != x.colume || colume != x.row)
	{
		row = x.colume;
		colume = x.row;
		delete [] matrix;
		matrix = new double [row * colume];
	}
	for(i = 1; i <= x.colume; i ++)
	{
		for(j = 1; j <= x.row; j ++)
		{
			(*this)(i, j) = x(j, i);
		}
	}
}


MATRIX MATRIX::Transpose_Matrix() const
{
	MATRIX x(colume, row);
	x.Transpose_Matrix(*this);
	return x;
}


double& MATRIX::operator ()(int row, int colume) const
{
	if(row < 1 || row > this->row || colume < 1 || colume > this->colume)
	{
		cout << "不正确的参数!" << endl;
		exit(1);
	}
	return this->matrix[(-- row) * this->colume + -- colume];
}

USINT MATRIX::Colume()const
{
	return this->colume;
}

USINT MATRIX::Row()const
{
	return this->row;
}

void MATRIX::Zero_Matrix(const MATRIX &x)
{
	if (row != x.row || colume != x.colume)
	{
		row = x.row;
		colume = x.colume;
		delete [] matrix;
		matrix = new double [row * colume];
	}
	for(int i = 0; i < row * colume; i ++)
	{
		matrix[i] = 0;
	}
}

MATRIX MATRIX::Zero_Matrix()const
{
	return MATRIX(this->row, this->colume);
}

void MATRIX::Rows_Exchange(const MATRIX &x, int row1, int row2)
{
	*this = x;
	if(row1 >= 1 && row1 <= x.row && row2 >= 1 && row2 <= x.row && row1 != row2)
	{
		for(int i = 1; i <= colume; i ++)
		{
			Swap((*this)(row1, i), (*this)(row2, i));
		}
	}
}
	
MATRIX MATRIX::Rows_Exchange(int row1, int row2)const
{
	MATRIX x(row, colume);
	x.Rows_Exchange(*this, row1, row2);
	return x;
}

void MATRIX::Swap(double &x, double &y)
{
	double z = x;
	x = y;
	y = z;
}

void MATRIX::Rows_Calculate(const MATRIX &x, int row1, int row2, double mutiple)
{
	*this = x;
	if(row1 != row2 && row1 >= 1 && row1 <= row && row2 >= 1 && row2 <= row)
	{
		for(int i = 1; i <= colume; i ++)
		{
			(*this)(row1, i) += (x(row2, i) * mutiple);
		}
	}
}
	
MATRIX MATRIX::Rows_Calculate(int row1, int row2, double mutiple)const
{
	MATRIX x(row, colume);
	x.Rows_Calculate(*this, row1, row2, mutiple);
	return x;
}

void MATRIX::SingleRow_Calculate(const MATRIX &x, int row1, double mutiple)
{
	*this = x;
	if(row1 >= 1 && row1 <= x.row)
	{
		for(int i = 1; i <= colume; i ++)
		{
			(*this)(row1, i) *= mutiple;
		}
	}
}

MATRIX MATRIX::SingleRow_Calculate(int row1, double mutiple)const
{
	MATRIX x(row, colume);
	x.SingleRow_Calculate(*this, row1, mutiple);
	return x;
}

void MATRIX::Ladder_line_matrix(const MATRIX &x)
{
	int i, j, k, m, a = x.row * x.colume;
	double mutiple;
	*this = x;
	for(i = 1; i <= row; i ++)
	{
		j = (i - 1) * (colume + 1);
		if(matrix[j] == 0)
		{
			k = i;
			m = j;
			while(m += colume, m < a && !matrix[m]) k ++;
			if(m >= a) break;
			*this = Rows_Exchange(i, k + 1);
		}
		for(k = i + 1; k <= row; k ++)
		{
			m = (k - i) * colume + j;
			mutiple = matrix[m] / matrix[j];
			*this = Rows_Calculate(k, i, -mutiple);
		}
	}
}

MATRIX MATRIX::Ladder_line_matrix()const
{
	MATRIX x(row, colume);
	x.Ladder_line_matrix(*this);
	return x;
}

void MATRIX::Erase_Colume(const MATRIX &x, int colume1)
{
	int i, j, k;
	if(colume1 < 1 || colume1 > x.colume) *this = x;
	else
	{
		if (row != x.row || colume != x.colume - 1)
		{
			row = x.row;
			colume = x.colume - 1;
			delete [] matrix;
			matrix = new double [row * colume];
		}
		k = 0;
		for(i = 1; i <= x.row; i ++)
		{
			for(j = 1; j <= x.colume; j ++)
			{
				if(j != colume1) matrix[k ++] = x(i, j);
			}
		}
	}
}
		
		
		

MATRIX MATRIX::Erase_Colume(int colume1)const
{
	MATRIX x(row, colume - 1);
	x.Erase_Colume(*this, colume1);
	return x;
}

void MATRIX::Columes_Exchange(const MATRIX &x, int colume1, int colume2)
{
	if(colume1 != colume2 && colume1 >= 1 && colume1 <= this->colume && colume2 >= 1 && colume2 <= this->colume)
	{
		*this = x;
		for(int i = 1; i <= row; i ++)
		{
			Swap((*this)(i, colume1), (*this)(i, colume2));
		}
	}
}


MATRIX MATRIX::Columes_Exchange(int colume1, int colume2)const
{
	MATRIX x(*this);
	if(colume1 != colume2 && colume1 >= 1 && colume1 <= this->colume && colume2 >= 1 && colume2 <= this->colume)
	{
		int j = colume1 - 1;
		int k = colume2 - 1;
		for(int i = 0; i < this->row; i ++)
		{
			x.Swap(x.matrix[j], x.matrix[k]);
			j += x.colume;
			k += x.colume;
		}
	}
	return x;
}
/*int main()
{
	MATRIX a(3, 2);
	MATRIX b;
	a.Input();
	a.Output(); cout << endl;
	b = a.Transpose_Matrix();
	b.Output(); cout << endl;
	cout << b(1, 3) << endl;
	return 0;
}*/
/*2x1 + 2x2 - x3 + x4 = 4,
4x1 + 3x2 - x3 + 2x4 = 6,
8x1 + 5x2 - 3x3 + 4x3 = 12,
3x1 + 3x2 - 2x3 + 2x4 = 6;
青 争 11:35:22
ok
刘观文 11:37:26
答案啊(1,1,-1,-1)

青 争 11:39:19
马上得出正确的答案

青 争 11:39:26
除了一些故障
刘观文 11:39:39
*/

/*int main()
{
	MATRIX a(2, 3);
	a.Input();
	a.Output();
	return 0;
}*/

/*int main()
{
	MATRIX a(3, 2), b(2, 3), c(3, 2), d(4, 4);
	cin >> a;
	cout << a << endl;
	cin >> b;
	cout << b << endl;
	cin >> c;
	cout << c << endl;
	d = c.Columes_Exchange(1, 2);
	cout << d << endl;
	d = c.Columes_Exchange(1, 3);
	cout << d << endl;
	return 0;
}*/
#ifndef _MATRIX_H_
#define _MATRIX_H_

typedef unsigned short int USINT;

class MATRIX
{
public:
	MATRIX(int row = 2, int colume = 2);
	MATRIX(const MATRIX& x);
	~MATRIX();
	const MATRIX& operator =(const MATRIX &x);

	void Input();
	void Output() const;
	friend istream& operator >>(istream& in, MATRIX &x);
	friend ostream& operator <<(ostream& out, const MATRIX &x);

	void Add(const MATRIX &x, const MATRIX &y);
	MATRIX operator +(const MATRIX &x) const;

	void Sub(const MATRIX &x, const MATRIX &y);
	MATRIX operator -(const MATRIX &x) const;

	MATRIX& operator +=(const MATRIX &x);

	MATRIX& operator -=(const MATRIX &x);

	bool operator ==(const MATRIX &x) const;
	bool operator !=(const MATRIX &x) const;
	
	void PositiveSign(const MATRIX &x);
	MATRIX operator +()const;

	void NegativeSign(const MATRIX &x);
	MATRIX operator -()const;
	
	void Mul(const MATRIX &x, const MATRIX &y);
	MATRIX operator *(const MATRIX &x) const;

	MATRIX& operator *=(const MATRIX &x);

	void Mul(const MATRIX &x, double y);
	MATRIX operator *(double x)const;
	friend MATRIX operator *(double x, const MATRIX& y);
	
	void Transpose_Matrix(const MATRIX &x);
	MATRIX Transpose_Matrix()const;

	double& operator ()(int row, int colume) const;

	USINT Colume()const;
	USINT Row()const;
	
	void Zero_Matrix(const MATRIX &x);
	MATRIX Zero_Matrix()const;
	
	void Rows_Exchange(const MATRIX &x, int row1, int row2);
	MATRIX Rows_Exchange(int row1, int row2) const;

	void Rows_Calculate(const MATRIX &x, int row1, int row2, double mutiple);
	MATRIX Rows_Calculate(int row1, int row2, double mutiple) const;

	void SingleRow_Calculate(const MATRIX &x, int row, double mutiple);
	MATRIX SingleRow_Calculate(int row, double mutiple) const;

	void Ladder_line_matrix(const MATRIX &x);
	MATRIX Ladder_line_matrix() const;

	void Erase_Colume(const MATRIX &x, int colume1);
	MATRIX Erase_Colume(int colume) const;
	
	void Columes_Exchange(const MATRIX &x, int colume1, int colume2);
	MATRIX Columes_Exchange(int colume1, int colume2) const;

	static void Swap(double &x, double &y);

protected:
	USINT row, colume;
	double *matrix;
};

#endif
#ifndef _SQUARE_MATRIX_H_

#define _SQUARE_MATRIX_H_

#include "MATRIX.H"

class SQUARE_MATRIX: public virtual MATRIX
{
public:
	SQUARE_MATRIX(int row = 2);
	SQUARE_MATRIX(const SQUARE_MATRIX &x);
	SQUARE_MATRIX& operator =(const SQUARE_MATRIX &x);
	SQUARE_MATRIX operator +(const SQUARE_MATRIX &x) const;
	
	SQUARE_MATRIX operator -(const SQUARE_MATRIX &x) const;

	SQUARE_MATRIX operator +()const;

	SQUARE_MATRIX operator -()const;
	
	SQUARE_MATRIX operator *(const SQUARE_MATRIX &x) const;

	SQUARE_MATRIX operator *(double x)const;
	friend SQUARE_MATRIX operator *(double x, const SQUARE_MATRIX& y);
	
	SQUARE_MATRIX Transpose_Matrix()const;
	
	SQUARE_MATRIX Zero_Matrix()const;
	
	SQUARE_MATRIX Rows_Exchange(int row1, int row2) const;

	SQUARE_MATRIX Rows_Calculate(int row1, int row2, double mutiple) const;

	SQUARE_MATRIX SingleRow_Calculate(int row, double mutiple) const;

	SQUARE_MATRIX Ladder_line_matrix() const;

	SQUARE_MATRIX Erase_Colume(int colume) const;
	
	SQUARE_MATRIX Columes_Exchange(int colume1, int colume2) const;


	SQUARE_MATRIX Power(int n)const;

	double Algebraic_Complement(int row, int colume)const;

	double Cofactor(int row, int colume)const;

	SQUARE_MATRIX Remainder_SQUARE_MATRIX(int row, int colume)const;

	SQUARE_MATRIX Unit_SQUARE_MATRIX()const;

	SQUARE_MATRIX Adjoint_SQUARE_MATRIX()const;

	SQUARE_MATRIX Inverse_SQUARE_MATRIX()const;

	double Determinant()const;

	bool IsInverseSQUARE_MATRIX(const SQUARE_MATRIX& x) const;

	SQUARE_MATRIX Triangle_SQUARE_MATRIX()const;

	bool IsSymmetricSQUARE_MATRIX()const;

	bool IsAntisymmetricSQUARE_MATRIX()const;

	bool SingularSQUARE_MATRIX()const;

	SQUARE_MATRIX DiagonalSQUARE_MATRIX()const;

	double RDeterminant()const;

protected:
	bool Parameter_IsValid(int row, int colume)const;
};


#endif
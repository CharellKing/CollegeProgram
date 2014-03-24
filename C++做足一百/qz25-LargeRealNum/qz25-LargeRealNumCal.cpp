//Large real Calculate

#include <iostream>

#include <cctype>

using namespace std;

const int M = 500;

const int point = 10;

bool InputLargeRealNum(char *s, int n);

void OutputLargeRealNum(const char *s);

void ConvertLargeRealNum(const char *s1, char *s2);

int FindPoint(const char *s);

void RealToInteger(const char *s1, char *s2, int digit);

int IsZero(const char *s);

void Equation(const char *s1, char *s2);

int IsLeftMax(char const *s1, char const *s2, int Num1, int Num2);

void Operation(const char *s1, const char *s2, int digit);

void LargeNumSum(const char *s1, const char *s2,  char *s3);

void Addition(const char *s1, const char *s2, char *s3);

void Minusce(const char *s1, const char * s2, char *s3);

void Multiplication(const char *s1, const char *s2, char *s3);

void Division(const char *s1, const char *s2, char *s3);

int LargeNumDigit(const char * s);

void EnlargeNum(const char *s1, char * s2, int mutiple);

void EnlargeDigit(const char *s1, char * s2, int n, int *num2);

void Equation(const char *s1, char *s2);

void LargeNumSwap(char *s1, char *s2);

double Involution(double index, int power);

void IntegerToChar(char *s1, int n, char *s2, int sign);

void IntegerToReal(const char *s1, char *s2, int digit); 

void StringNull(char *s, int n);

int main()
{
	char s1[M], s2[M], s3[M], s4[M], s5[M], s6[M];
	int point1, point2, digit1, digit2;
	cout <<"Please input one large real number:\n";
	while(StringNull(s1, M), !InputLargeRealNum(s1, M));
	ConvertLargeRealNum(s1, s3);
	cout <<"Please input another large real number:\n";
	while(StringNull(s2, M), !InputLargeRealNum(s2, M));
	ConvertLargeRealNum(s2, s4);
	point1 = FindPoint(s3);
	point2 = FindPoint(s4);
	if(point1 == -1 && -1 == point2) digit1 = 0, digit2 = 0;
	if(point1 == -1 && point2 != -1) digit1 = point2, digit2 = 0;
	if(point1 != -1 && point2 == -1) digit1 = 0, digit2 = point1;
	if(point1 != -1 && point2 != -1)
	{
		if(point1 < point2) digit1 = point2 - point1, digit2 = 0;
		else digit1 = 0; digit2 = point1 - point2;
	}
	RealToInteger(s3, s6, digit1);
	RealToInteger(s4, s5, digit2);
	if(point1 < point2) point1 = point2;
	Operation(s6, s5, point1);
	return 0;
}


bool InputLargeRealNum(char *s, int n)
{
	int i = n - 1, j, k = i;
	bool result = true;
	StringNull(s, M);
	do
	{
		cin.get(s[i--]);
	}
	while(s[i + 1] != 10);
	i ++;
	j = FindPoint(s);
	if(j == i + 1 || j == k) result = false;
	if(!isdigit(s[k]) && s[k] != '+' && s[k] != '-') result = false;
	if(s[k] == '0' && isdigit(s[k-1])) result = false;
	if(s[k] == '+' || s[k] == '-')
	{
		if(s[k-1] == '0' && s[k - 2] != '.') result = false;
	}
	for(--k; k > i && k > j; k --)
	{
		if(!isdigit(s[k])) result = false;
	}
	for(--k; k > i; k --)
	{
		if(!isdigit(s[k])) result = false;
	}
	if(!result) cout << "ERROR! Please input again!\n";
	return result;
}

void ConvertLargeRealNum(const char *s1, char *s2)
{
	int point, i = 0, j;
	point = FindPoint(s1);
	while(s1[i++] != 10);
	for(; s1[i] == '0' && s1[i] < point; i ++);
	if(i == point) i ++;
	for(j = 0; i < M - 1; s2[j++] = s1[i++]);
	if(s1[i] == '+') s2[j++] = 1;
	if(s1[i] == '-') s2[j++] = -1;
	if(isdigit(s1[i])) s2[j++] = s1[i], s2[j++] = 1;
	s2[j] = 10;
}

void OutputLargeRealNum(const char *s)
{
	int i = M - 1;
	while(s[i--] != 10);
	if(s[i] == 1) i --;
	if(s[i] == -1) i --, cout << "-";
	for(; i >= 0; cout << s[i--]);
	cout << endl;
}

int FindPoint(const char *s)
{
	int i;
	for(i = M - 1; i >= 0; i--)
	{
		if(s[i] == '.') return i;
	}
	return -1;
}

void StringNull(char *s, int n)
{
	for(; n >= 0;  s[-- n] = NULL);
}

void RealToInteger(const char *s1, char *s2, int digit)
{
	int i, j, m, n;
	for(i = 0; i < digit; s2[i++] = '0');
	for(j = 0; s1[j] != '.' && s1[j] != 10; s2[i ++] = s1[j ++]);
	if(s1[j] == '.') j ++;
	for(; s1[j] != 10; s2[i++] = s1[j++]);
	m = i - 1;
	for(n = i -2; n > 0 && s2[n] == '0'; n --);
	s2[++n] = s2[m];
	s2[++n] = 10;
	for(; n < M; s2[++n] = NULL);
}
void Operation(const char *s1, const char *s2, int digit)
{
	char s5[M], s6[M], s7[M], s8[M], s9[M], s10[M], choice, b;
	bool order1 = true;
	printf("CHOOSE OPERATION:(s - sum  m - multiplication d - division, e- end \n");
	do
	{
		StringNull(s5, M);
		StringNull(s6, M);
		StringNull(s7, M);
		StringNull(s8, M);
		StringNull(s9, M);
		StringNull(s10, M);
		choice = getchar();
		choice = tolower(choice);
		b = getchar();
		switch(choice)
		{
			case 's':
			LargeNumSum(s1, s2, s5);
			IntegerToReal(s5, s8, digit);
			OutputLargeRealNum(s8);
			break;
			case 'm':
			Multiplication(s1, s2, s6);
			IntegerToReal(s6, s9, 2 * digit);
			OutputLargeRealNum(s9);
			break;
			case 'd':
			Division(s1, s2, s7);
			IntegerToReal(s7, s10, -1);
			OutputLargeRealNum(s10);
			break;
			case 'e':
			order1 = false;
			break;
			default: printf("Input again:\n");
		}
	}
	while(order1);

}


void LargeNumSum(const char *s1, const char *s2, char *s3)
{
	char s4[M], s5[M];
	int k;
	if(IsZero(s1))
	{Equation(s2, s3); return;}
	if(IsZero(s2))
	{Equation(s1, s3); return;}
	int num1, num2;
	num1 = LargeNumDigit(s1);
	num2 = LargeNumDigit(s2);
	Equation(s1, s4);
	Equation(s2, s5);
	k = IsLeftMax(s1, s2, num1, num2);
	if(k < 0) LargeNumSwap(s4, s5);
	if(s1[num1] == s2[num2]) Addition(s4, s5, s3);
	if(s1[num1] != s2[num2] && k == 0) 
	{s3[0] = '0', s3[1] = 1, s3[2] = 10; return;}
	if(s1[num1] != s2[num2]) Minusce(s4, s5, s3);
}

void Addition(const char *s1, const char *s2, char *s3)
{
	int i, k = 2 * '0', m, num1, num2;
	char s4[M];
	Equation(s2, s4);
	num1 = LargeNumDigit(s1);
	num2 = LargeNumDigit(s2);
	for(; num2 < num1; s4[num2 ++] = '0');
	for(i = 0; i < num1; i ++)
	{
		m = s1[i] + s4[i] - k + s3[i];
		s3[i] = (m % 10 + '0');
		s3[i+1] += m / 10;
	}
	if(!s3[i]) s3[i] = s1[i], s3[i + 1] = 10;
	else s3[i] += '0', s3[i + 1] = s1[i], s3[i + 2] = 10;
}

void Minusce(const char *s1, const char * s2, char *s3)
{
	int i, k, m = 0, num1, num2;
	char s4[M];
	Equation(s2, s4);
	num1 = LargeNumDigit(s1);
	num2 = LargeNumDigit(s2);
	for(; num2 < num1; s4[num2 ++] = '0');
	for(i = 0; i < num1; i ++)
	{
		k = s1[i] - s4[i] - m, m = 0;
		if(k < 0) s3[i] = k + 10 + '0', m = 1;
		else s3[i] = k + '0';
	}
	k = i - 1;
	for(; s3[k] == '0' && k > 0; s3[k] = NULL, k --);
	s3[k + 1] = s1[i];
	s3[k + 2] = 10;
}

int IsZero(const char *s)
{
	return (s[0] == '0' && s[2] == 10);
}

int IsLeftMax(char const *s1, char const *s2, int Num1, int Num2)
{
	int k = Num1 - Num2;
	if(k > 0) return 1;
	else if(k < 0) return -1;
	else
	{
		for(-- Num1; Num1 >= 0; Num1 --)
		{
			if(s1[Num1] > s2[Num1]) return 1;
			if(s1[Num1] < s2[Num1]) return -1;
		}
	}
	return 0;
}

int LargeNumDigit(const char * s)
{
	int num = 0, i;
	for(i = 0; s[i] != 1 && s[i] != -1; i ++, num ++);
	if(FindPoint(s) != -1) num --;
	return num;
}

void Multiplication(const char *s1, const char *s2, char *s3)
{
	int i, j, k, num1, num2;
	if(IsZero(s1) || IsZero(s2))
	{s3[0] = '0', s3[1] = 1, s3[2] = 10; return ;}
	num1 = LargeNumDigit(s1);
	num2 = LargeNumDigit(s2);
	for(i = 0; i < num1; i ++)
	{
		for(j = 0; j < num2; j ++)
		{
			k = (s1[i] - '0') * (s2[j] - '0') + s3[i + j];
			s3[i + j] = k % 10;
			s3[i + j + 1] += k / 10;
		}
	}
	i = M;
	while(s3[--i] == NULL);
	s3[i + 1] = s1[num1] * s2[num2], s3[i + 2] = 10;
	for(; i >= 0; s3[i--] += '0');
}

void Division(const char *s1, const char *s2, char *s3)
{
	int k = M - 1, Num0, Num1, Num2, Num3, i, deltDigit, mutiple;
	if(IsZero(s1)) {s3[0] = '0', s3[1] = 1, s3[2] = 10; return ;}
	if(IsZero(s2)) printf("ERROR!\n"), exit(1);
	char s4[M], s5[M], s6[M], s[M];
	StringNull(s, M);
	EnlargeDigit(s1, s4, point + 1, &Num1);
	Num0 = LargeNumDigit(s1);
	Num2 = LargeNumDigit(s2);
	s4[Num1] = 1;
	if(IsLeftMax(s2, s4, Num2, Num1) == 1) s3[0] = '0', s3[1] = 1, s3[2] = 10;
	else
	{
		
		do
		{
			mutiple = 2, Equation(s2, s5), s5[Num2] = -1, deltDigit = Num1 - Num2;
			if(deltDigit > 1)
			EnlargeDigit(s5, s6, --deltDigit, &Num3), Equation(s6, s5),i = deltDigit;
			else i = 0;
			
			do
			{
				StringNull(s6, M); 
				EnlargeNum(s5, s6, mutiple++);
				Num3 = LargeNumDigit(s6);
			}
			while(IsLeftMax(s4, s6, Num1, Num3) == 1);
			StringNull(s6, M);
			mutiple -= 2;
			EnlargeNum(s5, s6, mutiple);
			s[i] += mutiple;
			StringNull(s5, M);
			LargeNumSum(s4, s6, s5);
			Equation(s5, s4);
			Num1 = LargeNumDigit(s4);
		}
		while(IsLeftMax(s4, s2, Num1, Num2) != -1);
		k = s1[Num0] * s2[Num2];
		IntegerToChar(s, Num0 + point + 1, s3, k);
	}
}

double Involution(double index, int power)
{
	double sum = 1, i;
	for(i = 0; i < power; sum *= index, i ++);
	return sum;
}

void IntegerToChar(char *s1, int n, char *s2, int sign)
{
	int i = 1, j;
	s1[1] += (s1[0] / 10), s1[0] %= 10;
	if(s1[0] >= 5) s1[1] ++;
//	while((!s1[--n]) && (n > point + 1));
	for(--n; s1[n] == 0 && n > point + 1; n --);
//	while((!s1[i++]) && (i < point + 1));
	for(; s1[i] == 0 && i < point + 1; i ++);
	if(i == point + 1) for(j = 0; j <= n; s2[j++] = s1[i] % 10 + '0', s1[i] += (s1[i++] / 10));
	else
	{
		for(j = 0; i < point + 1; j ++, i ++)
		{
			s2[j] = s1[i] % 10 + '0', s1[i+ 1] += (s1[i] / 10);
		}
		s2[j++] = '.';
		for(; i <= n; j ++, i ++)
		{
			s2[j] = s1[i] % 10 + '0', s1[i + 1] += (s1[i] / 10);
		} 
		if(s1[i])  s2[j++] = s1[i] + '0';
	}
	s2[j++] = sign;
	s2[j] = 10;
}


void EnlargeNum(const char *s1, char * s2, int mutiple)
{
	int k = 0 , m;
	char s3[M];
	do
	{
		m = mutiple % 10;
		mutiple /= 10;
		s3[k++] = ('0' + m);
	}
	while(mutiple);
	s3[k] = 1;
	s3[k +1] = 10;
	Multiplication(s1, s3, s2);
}


void LargeNumSwap(char *s1, char *s2)
{
	char s3[M];
	Equation(s1, s3);
	Equation(s2, s1);
	Equation(s3, s2);
}

void Equation(const char *s1, char *s2)
{
	int i;
	for(i = 0; i < M; s2[i++] = s1[i]);
}

void EnlargeDigit(const char *s1, char * s2, int n, int *num2)
{
	int i, j;
	for(i = 0; i < n; s2[i ++] = '0');
	for(j = 0; s1[j]; s2[i ++] = s1[j++]);
	*num2 = i - 2;
	for(; i < M; s2[i++] = NULL);
}

void DecreaceDigit(const char *s1, char *s2, int n, int *num3)
{
	int i = n, j;
	for(j = 0; i < M; s2[j++] = s1[i++]);
	for(;j < M; s2[j++] = NULL);
}


void IntegerToReal(const char *s1, char *s2, int digit)
{
	int num, point1, i, j, k, digit2, digit3;
	char s3[M];
	num = LargeNumDigit(s1);
	point1 = FindPoint(s1);
	for(i = 0; i < point1; s3[i] = s1[i], i ++);
	j = i;
	if(j == point1) j ++;
	for(k = 0; k < digit;  k ++)
	{
		if(!isdigit(s1[j])) s3[i ++] = '0', j ++;
		else s3[i ++] = s1[j ++];
	}
	s3[i++] = '.';
	if(isdigit(s1[j])) for(; i < M; s3[i++] = s1[j++]);
	else 
	{
		s3[i ++] = '0';
		if(point1 == -1) s3[i ++] = s1[num];
		else s3[i ++] = s1[num + 1];
		s3[i++] = 10;
	}
	if(point1 == -1 && digit != -1) digit2 = digit;
	if(point1 != -1 && digit == -1) digit2 = point1;
	if(point1 == -1 && digit == -1) digit2 = 0;
	digit3 = digit2 - point;
	if(digit3 <= 0)
	{
		for(i = 0; i < -digit3; s2[i ++] = '0');
		for(j = 0; i < M; s2[i ++] = s3[j ++]);
	}
	else
	{
		for(j = digit3, i = 0; j < M; s2[i ++] = s3[j++]);
		for(; i < M; s2[i++] = NULL);
	}
}

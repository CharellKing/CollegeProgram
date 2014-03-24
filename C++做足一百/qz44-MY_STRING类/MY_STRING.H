#ifndef _MY_STRING_H_

#define _MY_STRING_H_

class MY_STRING
{
public:
	MY_STRING();
	MY_STRING(const char *s);
	MY_STRING(const MY_STRING &x);
	~MY_STRING()
	{
	}
	friend istream& operator>>(istream& in, MY_STRING &x);
	void Destroy();
	friend ostream& operator<<(ostream& out, MY_STRING &x);
	MY_STRING operator=(const MY_STRING &x);
	friend bool operator>(const MY_STRING &left, const MY_STRING &right);
	friend bool operator<(const MY_STRING &left, const MY_STRING &right);
	friend bool operator!=(const MY_STRING &left, const MY_STRING &right);
	friend bool operator>=(const MY_STRING &left, const MY_STRING &right);
	friend bool operator<=(const MY_STRING &left, const MY_STRING &right);
	friend bool operator==(const MY_STRING &left, const MY_STRING &right);
	friend MY_STRING operator+(const MY_STRING &x, const MY_STRING &y);
	bool IsEmpty();
	int Size();
	char* StringToCharArray();
private:
	char *elements;
	int size;
};
#endif
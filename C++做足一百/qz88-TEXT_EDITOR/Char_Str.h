#ifndef _Char_Str_H_

#define _Char_Str_H_

typedef unsigned int UINT;

const int INIT_SIZE = 20;
const int INCREASEMENT = 30;

class MyString
{
public:
	MyString(int size = INIT_SIZE);
	MyString(const MyString& x);
	~MyString();
	const MyString& operator =(const MyString T);
	char operator[](int pos);
	void Input();
	void Append(char c);
	void Output()const;
	bool IsEmpty()const;
	int StrCompare(const MyString& x)const;
	UINT Length()const;
	void Clear();
	MyString ConCat(const MyString& x);
	MyString SubStr(int pos, int length);
	int Index(const MyString& x);
	MyString Replace(const MyString& passive, const MyString& initiative);
	MyString StrInsert(int pos, const MyString& t);
	MyString StrDelete(int pos, int length);
	static void ExpendSpace(char* &data, int sum_size);
    static void ConCat(MyString& x, const MyString& y);
	static void SubStr(MyString& x, int pos, int length);
	static void Replace(MyString& x, const MyString& passive, const MyString& initiative);
	static void StrInsert(MyString& x, int pos, const MyString& t);
	static void StrDelete(MyString& x, int pos, int lenght);
private:
	static bool Matched_Behind(const char* data, int pos, int before);
	char* data;
	UINT size, length;
};

#endif

#ifndef _SQLIST_H_

#define _SQLIST_H_

class SQLIST
 {
public:
	SQLIST();
	void Insert(int x);
	int Before_Min(int x);
	bool IsFull();
	void Output();
protected:
	int data[20];
	int length;
 };

#endif
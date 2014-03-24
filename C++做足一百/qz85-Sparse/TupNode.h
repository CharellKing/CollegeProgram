#ifndef _TupNode_h_

#define _TupNode_h_

typedef unsigned UINT;

template <typename T>

class TupNode
{
public:
	TupNode(const T& data = T(), int row = 0, int column = 0);
	void Data(const T& data);
	void Data_negate();
	T Data()const;
	void Row(int row);
	int Row()const;
	void Column(int column);
	int Column()const;
protected:
	T data;
	int row;
	int column;
};

template <typename T>
TupNode<T>::TupNode(const T& data, int row, int column)
{
	this->data = data;
	if(row < 0) row = 0;
	if(column < 0) column = 0;
	this->row = row;
	this->column = column;
}
template <typename T>
void TupNode<T>::Data(const T& data)
{
	this->data = data;
}

template <typename T>
void TupNode<T>::Data_negate()
{
	data = -data;
}

template <typename T>
T TupNode<T>::Data()const
{
	return data;
}

template <typename T>
void TupNode<T>::Row(int row)
{
	this->row = row;
}

template <typename T>
int TupNode<T>::Row()const
{
	return row;
}

template <typename T>
void TupNode<T>::Column(int column)
{
	this->column = column;
}

template <typename T>
int TupNode<T>::Column()const
{
	return column;
}

#endif
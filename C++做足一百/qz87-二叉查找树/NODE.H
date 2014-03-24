#ifndef _NODE_H_

#define _NODE_H_

template <typename T>
class NODE
{
public:
	NODE(T data = T(), NODE<T>* left = NULL, NODE<T>* right = NULL);
	T data;
	NODE<T> *left, *right;
};

template <typename T>
NODE<T>::NODE(T data, NODE<T>* left, NODE<T>* right):data(data), left(left), right(right)
{

}

#endif
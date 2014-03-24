#ifndef _NODE_H_

#define _NODE_H_

template <typename T>
class NODE
{
public:
	NODE(T data = T(), NODE* next = NULL);
	NODE*& Next();
	T& Data();
private:
	NODE *next;
	T data;
};

template <typename T>
NODE<T>::NODE(T data, NODE* next) : data(data), next(next)
{
	
}

template <typename T>
NODE<T>*& NODE<T>::Next()
{
	return next;
}

template <typename T>
T& NODE<T>::Data()
{
	return data;
}



#endif

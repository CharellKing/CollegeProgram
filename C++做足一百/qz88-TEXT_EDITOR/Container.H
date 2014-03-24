#ifndef _Container_h_

#define _Container_h_

const unsigned int CONTAINER_INIT_SIZE = 20;
const unsigned int CONSTAINER_INCREASEMENT = 30;

template <typename T>
class Container
{
public:
    typedef T* point;
    Container(int size = CONTAINER_INIT_SIZE);
    ~Container();
    Container(const Container<T>& x);
    const Container& operator =(const Container<T>& x);
    void Append(const T& x);
    void DeElement(int pos);
    void InsertElenment(int pos, const T& x); 
protected:
    point* data;
    unsigned int size;
    unsigned int length;
};

template <typename T>
Container<T>::Container(int size)
{
    if(size <= 0) size = CONTAINER_INIT_SIZE;
    this->size = size;
    data = new point [this->size];
}

template <typename T>
Container<T>::~Container()
{
    delete [] data;
}

template <typename T>
Container<T>::Container(const Container<T>& x)
{
    size = x.size;
    length = x.length;
    data = new point [x.size];
}

template <typename T>
const Container<T>& Container<T>::operator =(const Container<T>& x) 
{
    int i;
    if(this != &x)
    {
        if(x.size != size)
        {
            size = x.size;
            delete [] data;
            data = new point [size];
        }
        length = x.length;
        for(i = 0; i < length; i ++)
        {
            *data[i] = x.*(data[i]);
        }
    }
    return *this;
}

template <typename T>
void Container<T>::Append(const T& x)
{
    if(length < size)
    {
        *data[length] = x;
    }
}

template <typename T>
void Container<T>::DeElement(int pos)
{
    int i, k = length - 1;
    if(pos >= 1)
    {
        for(i = pos - 1; i < k; i ++)
        {
            *data[i] = *data[i + 1];
        }
    }
}


template <typename T>     
void Container<T>::InsertElenment(int pos, const T& x)
{
    int i, k;
    if(pos >= 1)
    {
        for(i = pos - 1; i < length; i ++)
        {
            *data[i + 1] = *data[i];
        }
        *data[pos - 1] = x;
    }
}
#endif

#include <iostream>

using namespace std;

template <class T> class Vector
{
private:
    T* a;
    int size, capacity;
public:
    Vector();
    ~Vector();
    int length();
    void push(T element);
    void pop();
    T get(int index);
    bool isEmpty();
    
};

template <class T> Vector<T>::Vector()
{
    a = new T[1];
    capacity = 10;
    size = 0;
}

template <class T> Vector<T>::~Vector()
{
    delete[] a;
}

template <class T> int Vector<T>::length()
{
    return size;
}

template<class T> void Vector<T>::push(T element)
{
    if(capacity <= size) 
    {
        capacity *= 2;
        T *newA = new T[capacity];
        for(int i = 0; i < size; i++)
        {
            newA[i] = a[i];
        }
        a = newA;
    }
    a[size] = element;
    size++;
}

template<class T> T Vector<T>::get(int index)
{
    if(size > 0 && index > 0 && index < size) return a[index];
    return -1;
}

template<class T> bool Vector<T>::isEmpty()
{
    return !size;
}

template<class T> void Vector<T>::pop()
{
    a[size - 1] = nullptr;
    size--;
}


int main()
{
    Vector<int> a;
    a.push(1);
    a.push(3);
    a.push(12);
    cout << a.get(1);
    return 0;
}
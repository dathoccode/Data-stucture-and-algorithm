#include <iostream>

using namespace std;

template <class T> class Stack
{
private:
    int capacity;
    int size;
    T *store; 
public:
    Stack();
    void push(T data);
    T pop();
    T top();
    bool isEmpty();
    int getSize();
    void show();
};

//constructor
template<class T> Stack<T>::Stack()
{
    this->capacity = 2;
    this->size = 0;
    this->store = new T[capacity];
}

//size
template <class T> int Stack<T> :: getSize()
{
    return this->size;
}

//isEmpty
template<class T> bool Stack<T>::isEmpty()
{
    return !this->size;
}

//push
template <class T> void Stack<T> :: push (T data)
{
    if(this->size >= this->capacity)
    {
        this->capacity *= 2;
        T *temp = new T[this->capacity];
        for(int i = 0; i < size; i++)
        {
            temp[i] = this->store[i];
        }
        this->store = temp;
    }
    this->store[size] = data;
    size++;
}

//pop
template <class T> T Stack<T> :: pop()
{
    if(this->size <= 0) return NULL;
    T res = this->store[this->size-1];
    this->store[this->size-1] = NULL;
    this->size--;
    return res;
}

//top
template <class T> T Stack<T> :: top()
{
    if(this->size <= 0) return NULL;
    T res = this->store[this->size-1];
    return res;
}

//show
template <class T> void Stack<T> :: show()
{
    for(int i = 0; i < this->size; i++)
    {
        cout << this->store[i] << " ";
    }
    cout << endl;
}







int main()
{
    Stack<int> a;
    bool stop = true;
    while(stop)
    {
        cout << "-----------------MENU---------------\n";
		cout << "1. push\n";
		cout << "2. pop\n";
		cout << "3. top\n";
		cout << "4. is empty\n";
		cout << "5. size\n";
        cout << "6. show stack\n";
		cout << "0. Thoat !\n";
		cout << "-------------------------------------\n";
		cout << "Nhap lua chon :";
        int input;
        cin >> input;
        switch(input)
        {
            case 1:
            {
                int data;
                cout << "nhap so can push: ";
                cin >> data;
                a.push(data);
                break;
            }
            case 2:
            {
                cout << "pop: " << a.pop() << endl;
                break;
            }
            case 3:
            {
                cout << "top: " << a.top() << endl;
                break;
            }
            case 4:
            {
                if(a.isEmpty()) cout << "stack is empty" << endl;
                else cout << "stack is not empty" << endl;
            }
            case 5:
            {
                cout << "size: " << a.getSize() << endl;
                break;
            }
            case 6:
            {
                a.show();
                break;
            }
            case 0:
            {
                stop = false;
                break;
            }
            default:
            {
                break;
            }
        }
    }
    return 0;
}
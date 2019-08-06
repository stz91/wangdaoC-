#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

template <class T, int kSize = 10>
class Stack
{
public:
    Stack()
        : _top(-1), _data(new T[kSize]())
    {
    }
    ~Stack()
    {
        delete [] _data;
    }

    bool full() const;
    bool empty() const;
    void push(const T &t);
    T &pop();
    T &top() const;

private:
    int _top;
    T *_data;
};

template <class T, int kSize>
bool Stack<T, kSize>::full() const
{
    return _top == kSize - 1;
}

template <class T, int kSize>
bool Stack<T, kSize>::empty() const
{
    return _top == -1;
}

template <class T, int kSize>
void Stack<T, kSize>::push(const T &t)
{
    if (!full())
    {
        _data[++_top] = t;
    }
    else
    {
        cout << "Stack is full!" << endl;
    }
}

template <class T, int kSize>
T &Stack<T, kSize>::pop()
{
    if (!empty())
    {
        return _data[_top--];
    }
    else
    {
        cout << "Stack is empty!" << endl;
    }
}
template <class T, int kSize>
T &Stack<T, kSize>::top() const
{
    if (!empty())
    {
        return _data[_top];
    }
    else
    {
        cout << "Stack is empty!" << endl;
    }
}

void test0()
{
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    for (int i = 0; i < 3; ++i)
    {
        cout << stack.pop() << endl;
    }
}

void test1()
{
    Stack<string> stack;
    stack.push("hello");
    stack.push("world");
    stack.push("helloworld");
    for (int i = 0; i < 3; ++i)
    {
        cout << stack.pop() << endl;
    }
}

int main(void)
{
    //test0();
    test1();
    return 0;
}
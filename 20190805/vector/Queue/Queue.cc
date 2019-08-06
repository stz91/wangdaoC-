#include <iostream>
using std::cout;
using std::endl;

template <class T, int qSize = 10>
class Queue
{
public:
    Queue()
        : _data(new T[qSize]()), _front(0), _tail(0)
    {
        cout << "Queue()" << endl;
    }
    ~Queue()
    {
        delete[] _data;
    }
    bool empty() const;
    bool full() const;
    void push(const T t);
    void pop(T &t);
    T top() const;

private:
    int _front;
    int _tail;
    T *_data;
};

template <class T, int qSize>
bool Queue<T, qSize>::empty() const
{
    if (_front == _tail)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

template <class T, int qSize>
bool Queue<T, qSize>::full() const
{
    if ((_front + 1) % qSize == _tail)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

template <class T, int qSize>
void Queue<T, qSize>::push(const T t)
{
    if (!full())
    {
        _data[_front] = t;
        _front = (_front + 1) % qSize;
    }
    else
    {
        cout << "Queue is full" << endl;
    }
}

template <class T, int qSize>
void Queue<T, qSize>::pop(T &t)
{
    if (!empty())
    {
        t = _data[_tail];
        _tail = (_tail + 1) % qSize;
    }
}

template <class T, int qSize>
T Queue<T, qSize>::top() const
{
    if (!empty())
    {
        return _data[_tail];
    }
}

void test0()
{
    Queue<int, 10> q1;
    cout << "q1是否为空" << q1.empty() << endl;
    for (int i = 0; i < 10; i++)
    {
        q1.push(i);
    }
    cout << "q1是否为满" << q1.full() << endl;
    for (int i = 0; i < 9; ++i)
    {
        int tmp;
        q1.pop(tmp);
        cout << tmp << " ";
    }
    cout << endl;
    cout << "q1是否为空" << q1.empty() << endl;
}

int main(void)
{
    test0();
    return 0;
}
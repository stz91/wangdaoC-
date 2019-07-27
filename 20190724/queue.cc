#include <iostream>
using std::cout;
using std::endl;

class queue
{
public:
    queue()
        : _intStack(new int[10]()), _tail(0), _front(0)
    {
        cout << "queue()" << endl;
    }
    bool empty()
    {
        if (_tail == _front)
        {
            cout << "queue is empty" << endl;
            return 1;
        }
        else
        {
            cout << "queue is not empty" << endl;
            return 0;
        }
    }
    bool full()
    {
        if ((_front + 1) % 10 == _tail)
        {
            cout << "queue if full" << endl;
            return 1;
        }
        else
        {
            cout << "queue is not full" << endl;
            return 0;
        }
    }
    bool push(int value)
    {
        if (full())
        {
            return 0;
        }
        _intStack[_front] = value;
        _front = (_front + 1) % 10;
        cout << "push success" << endl;
        return 1;
    }
    bool pop(int &value)
    {
        if (empty())
        {
            return 0;
        }
        value = _intStack[_tail];
        _tail = (_tail + 1) % 10;
        cout << "pop success" << endl;
        return 1;
    }
    int front()
    {
        if(!empty())
        {
            return _intStack[--_front];
        }
        return -1;
    }
    int tail()
    {
        if(!empty())
        {
            return _intStack[_tail];
        }
        return -1;
    }
    ~queue()
    {
        delete _intStack;
        cout << "~stack" << endl;
    }

private:
    int *_intStack;
    int _tail;
    int _front;
};

int main()
{
    queue q1;
    int val=0;
    q1.pop(val);
    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.pop(val);
    cout << "val = " << val << endl;
    q1.pop(val);
    cout << "val = " << val << endl;
    q1.pop(val);
    cout << "val = " << val << endl;
    return 0;
}
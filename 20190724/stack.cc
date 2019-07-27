#include <iostream>
using std::cout;
using std::endl;

class stack
{
public:
    stack()
    : _intStack(new int[10]())
    , _top(0)
    {
        cout << "stack()" << endl;
    }
    bool push(int value)
    {
        if(_top == 9)
        {
            cout << "Stack is full" << endl;
            return false;
        }
        _intStack[_top] = value;
        _top++;
        return true;
    }
    bool pop(int & value)
    {
        if(_top == 0)
        {
            cout << "Stack is empty" << endl;
            return false;
        }
        _top--;
        value = *_intStack;
        return true;
    }
    bool empty()
    {
        if(_top == 0)
            return 1;
        else
        {
            return 0;
        }
        
    }
    bool full()
    {
        if(_top == 9)
            return 1;
        else
        {
            return 0;
        }
        
    }
    ~stack()
    {
        cout << "~stack" << endl;
        delete _intStack;
    }
private:
    int * _intStack;
    int _top;
};

int main()
{
    stack s1;
    char c;
    int value=0;
    int tempValue;
    while(1)
    {
        cout << "a.插入数据" << endl
             << "b.取出数据" << endl
             << "c.退出" << endl;
        fflush(stdout);
        c=getchar();
        if(c == 'a')
        {
            value = getchar();
            s1.push(value);
        }
        if(c == 'b')
        {
            s1.pop(tempValue);
            cout << "tempValue = " << tempValue << endl;
        }
        if(c == 'c')
        {
            break;
        }
    }
    return 0;
}

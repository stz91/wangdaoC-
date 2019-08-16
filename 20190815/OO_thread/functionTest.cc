#include <iostream>
#include <functional>

using namespace std;

// C++语言中有几种可调用的对象：函数，指针，函数指针，
// lambda表达式，bind创建的对象以及重载了函数调用付的类

void printA(int a)
{
    cout << a << endl;
}

class Foo
{
public:
    Foo(int num)
    : _num(num)
    {
        cout << "Foo(int)" << endl;
    }
    void print(int i) const
    {
        cout << "num = " << _num + i << endl;
    }
    int _num;
};

int main()
{
    // function<void(int)> func;
    // func = printA;
    // func(2);
    // function<void()> func1 = [](){   cout << "helloworld" << endl;   };
    // func();

    function<void(const Foo &, int)> func2 = &Foo::print;
    Foo foo(2);
    func2(foo, 1);
    return 0;
}
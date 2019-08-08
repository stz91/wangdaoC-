#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <functional>
using namespace std;

void display()
{
    cout << "display()" << endl;
}

void print()
{
    cout << "print()" << endl;
}
//函数指针
typedef void (*Function)();

class Example
{
public:
    Example() = default;
    void display()
    {
        cout << "Example::display()" << endl;
    }

    int add(int x, int y)
    {
        return x + y;
    }
    int _data = 10;
};

void test0()
{
    //函数指针
    void (*f)() = display;
    f();

    f = print;
    f();
}

int add(int x, int y)
{
    return x + y;
}

void test1()
{
    Function f = display;
    f();
    f = print;
    f();
}

void test2()
{
    //函数的容器  类模板
    //bind  是函数模板，其返回值是函数对象
    function<void()> f = display;
    f();

    f = print;
    f();

    Example e;
    f = bind(&Example::display, e);

    f();
}

void test3()
{
    auto f = bind(add, 1, 2);
    cout << f() << endl;
    using namespace placeholders;
    //占位符
    auto f2 = bind(add, 1, placeholders::_1);
    cout << f2(100) << endl;

    auto f3 = bind(add, _1, 10);
    cout << f3(2) << endl;
    //如果使用地址传递，当函数调用时，要确保对象生命周期还存在
    Example e;
    // auto f4 = bind(&Example::add, &e, _1, _2);
    // cout << f4(1, 2) << endl;

}

int func(int x1, int x2, int x3, int & y)
{
    cout << "{" << x1 << ", " << x2 << ", " << x3 << ", " << y << ")" << endl;
}

void test4()
{
    using namespace placeholders;
    int a = 10;
    //ref 引用的包装器
    auto f = bind(func, _2, _1, a, ref(a));
    a = 20;
    //位置必须对应
    f(1, 2);    
}

int main(void)
{
    // test2();
    // test3();
    test4();
    return 0;
}
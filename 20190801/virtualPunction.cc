#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
    //构造函数不能设计成虚函数
    Base(long base)
        : _base(base)
    {
        cout << "Base(long)" << endl;
    }
    //1.虚函数的实现
    //当基类定义了虚函数之后,再其储存布局的开始位置会多一个
    //虚函数指针,该虚函数指针只想了一张虚函数表.虚函数表中
    //存放的是虚函数的入口地址
    //
    //2.虚函数(动态多态)机制激活的条件
    //>a.基类有定义虚函数,派生类覆盖基类虚函数
    //>b.创建派生类对象
    //>c.用基类的指针或者引用指向派生类对象
    //>d.用基类指针或者

    virtual void print() const
    {
        cout << ">> _base = " << _base << endl;
    }
    virtual void print(int x) const
    {
        cout << "x = " << x << endl;
    }

private:
    long _base;
};

class Derived
    : public Base
{
public:
    Derived(long base, long derived)
        : Base(base), _derived(derived)
    {
        cout << "Derived(long, long)" << endl;
    }
    void print() const
    {
        cout << ">> _derived = " << _derived << endl;
    }
    // void print(int x) const
    // {
    //     cout << "x = " << x << endl;
    // }
private:
    long _derived;
};

class GrandSon
    : public Derived
{
};

void print(Base *base)
{
    base->print();
    //base->print(1);
}

void print(Base &ref)
{
    ref.print();
}

int main()
{
    Base base(1);
    Derived d1(11, 12);
    print(&base);
    print(&d1);

    cout << endl;
    print(base);
    print(d1);

    //静态
    cout << endl;
    d1.print();
    return 0;
}
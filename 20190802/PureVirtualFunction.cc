#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
    //定义了纯虚函数的类成为抽象类
    //纯虚函数的特点,没有实现,作为接口存在  
    //对修改关闭,对拓展开放
    virtual void display() = 0;
    virtual void print() = 0;
};

class Child
: public Base
{
public:
    //派生类必须实现所有的纯虚函数,此时才能正常创建
    void display() override
    {
        cout << "child::display()" << endl;
    }
    void print() override
    {
        cout << "child2()" << endl;
    }
};

class Child2
: public Base
{
public:
    //派生类必须实现所有的纯虚函数,此时才能正常创建
    
};


int main()
{
    Base *pBase;
    Child child1;
    pBase = &child1;
    pBase->display();
    return 0;
}
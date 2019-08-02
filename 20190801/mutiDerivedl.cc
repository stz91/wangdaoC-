#include <iostream>
using std::endl;
using std::cout;

class A
{
public:
    void print() const
    {
        cout << "A:print()" << endl;
    }
};

class B
{
public:
    void print() const
    {
        cout << "B:print()" << endl;
    }
};

class C
{
public:
    void print() const
    {
        cout << "C:print()" << endl;
    }
};

class D
: public A
, public B
, public C
{

};

int main(void)
{
    D d;
    d.A::print();
    d.B::print();
    d.C::print();
    return 0;
}
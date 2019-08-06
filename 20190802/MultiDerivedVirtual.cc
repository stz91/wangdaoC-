#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
    virtual void a()
    {
        cout << "A::a()" << endl;
    }
    virtual void b()
    {
        cout << "B::b()" << endl;
    }
    virtual void c()
    {
        cout << "C::c()" << endl;
    }
};

class B
{
public:
    virtual void a()
    {
        cout << "B::a()" << endl;
    }
    virtual void b()
    {
        cout << "B::b()" << endl;
    }
    void c()
    {
        cout << "B::c()" << endl;
    }
    void d()
    {
        cout << "B::d()" << endl;
    }
};

class C
    : public A,
      public B
{
public:
    virtual void a()
    {
        cout << "C::a()" << endl;
    }
    void c()
    {
        cout << "C::c()" << endl;
    }
    void d()
    {
        cout << "C::d()" << endl;
    }
};

int main()
{
    C c;
    c.B::b();
    A &pa = c;
    pa.a();
    pa.b();
}
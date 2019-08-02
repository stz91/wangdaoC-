#include <iostream>
using std::endl;
using std::cout;

class A
{
public:
    void print() const
    {
        cout << _a << endl;
    }
private:
    long _a;
};

class B
: virtual public A
{

};

class C
: virtual public A
{};

class D
: public B
, public C
{};

int main(void)
{
    //d.print() //存储的二义性问题
    D d;
    d.print();//采用虚拟继承的方式
}
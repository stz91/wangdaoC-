#include <iostream>
using std::endl;
using std::cout;

class Base
{
public:
    Base(long base)
    : _base(base)
    {
        cout << "Base(long)" << endl;
    }
    void Print()
    {
        cout << "_base = " << _base << endl;
    }
private:
    long _base;
};

class Derived
: public Base
{
public:
    Derived(long base1, long base2)
    : Base(base1)
    , _base(base2)
    {
        cout << "base = " << _base << endl;
        using std::endl;
        using std::cout;
    }
    void Print(int a)
    {
        cout << "Pring(int)" << endl;
    }
private:
    long _base;
};

int main(void)
{
    Derived d1(11, 12);
    d1.Print(5);
    d1.Base::Print();
    return 0;
}
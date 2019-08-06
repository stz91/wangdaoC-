#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
    virtual void display()
    {
        cout << "_base = " << _base << endl;
    }
protected:
    Base(long base)
    : _base(base)
    {
        cout << "Base(long)" << endl;
    }
private: 
    long _base;
};

class Derived
: public Base
{
public:
    Derived(long base, long derived)
    : Base(base)
    , _derived(derived)
    {
        cout << "Derived(long base, long derived)" << endl;
    }
    void display()
    {
        cout << "_derived = " << _derived << endl;
    }
private:
    long _derived;
};

int main(void)
{
    Derived derived(1, 2);
    Base *pbase = &derived;
    pbase->display();//在编译时传递默认参数进去,所以只能使用基类的默然参数
    return 0;
}
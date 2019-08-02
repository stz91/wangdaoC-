#include <iostream>
using std::endl;
using std::cout;


//先去调用派生类的构造函数,在调用期间再去调用基类函数
class Base
{
public: 
    Base()
    {
        cout << "Base()" << endl;
    }
    Base(long base)
    : _base(base)
    {
        cout << "Base(long)" << endl;
    }
    ~Base()
    {
        cout << "~Base()" << endl;
    }
private:
    long _base;
};

class Derived
: public Base
{
public:
    Derived()
    {
        cout <<"Derived()" << endl;
    }
    Derived(long base)
    : Base(base)
    {
        cout << "Derived(long)" << endl;
    }
    //当派生类对象被销毁是,先调用派生类析构函数,然后在自动调用
    //基类的析构函数
    ~Derived()
    {
        cout << "~Derived()" << endl;
    }
};

int main(void)
{
    Derived d1;
    return 0;
}
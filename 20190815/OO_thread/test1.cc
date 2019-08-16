#include <iostream>
#include <memory>

using namespace std;

class Base
{
private:
    virtual void run() = 0;
public:
    void fun()
    {
        Base * base = this;
        base->run();
    }
};

class Derived
: public Base
{
public:
    void run() override
    {
        cout << ">> Derived::run()" << endl;
    }
};

int main(void)
{
    unique_ptr<Base> p(new Derived());
    p->fun();
    return 0;
}
#include <iostream>
using std::cout;
using std::endl;

class Grandpa
{
public:
    Grandpa(int d1)
    : _d1(d1)
    {
        cout << "Grandpa(long)" << endl;
    }
    virtual void func1()
    {
        cout << "Grandpa void func1()" << endl;
    }
    virtual void func22()
    {
        cout << "grandpa void func2()" << endl;
    }
private:
    long _d1;
};

class Son
{
public:
private:
    long _d2;
};

class GrandSon
{
public:
private:
    long _d3
};

int main()
{
}
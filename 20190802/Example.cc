#include <iostream>
using std::cout;
using std::endl;

#pragma pack(push)
#pragma pack(4)


class Base
{
public:
    virtual void display() const
    {
        cout << "display()" << endl;
    }
};

//默认情况下按8字节对齐

class Example
: public Base
{
public:
    virtual void display() const    //8
    {
        cout << "display()" << endl; 
    }
private:
    int _d1;            //4
    double _d2;         //8
    char _d3;           //1
    short _d4[5];       //10
    int & _d5;          //8
    static double _d6;  //8
};

#pragma pack(pop);

int main()
{
    return 0;
}
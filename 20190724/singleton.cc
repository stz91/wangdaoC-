#include <iostream>
using std::cout;
using std::endl;

class singleton
{
public:
    static singleton * getInstance()
    {
        if(nullptr == p)
        {
            p = new singleton();
        }
        return p;
    }
    static void destory()
    {
        if(p)
        {
            delete p;
        }
    } 
private:
    static singleton * p;
    singleton(){}
    ~singleton(){   cout << "~singleton" <<endl; }
};

singleton * singleton::p = nullptr;

int main()
{
    singleton * p1 = singleton::getInstance();
    singleton * p2 = singleton::getInstance();
    cout  << "p1=" << p1 << endl;
    cout  << "p2=" << p2 << endl;
    singleton::destory();
    return 0;
}
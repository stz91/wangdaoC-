#include <iostream>
#include <stdlib.h>
#include <pthread.h>
using std::cout;
using std::endl;

class singleton
{
public:
    static singleton *getInstance()
    {
        pthread_once(&_once, init);
        return p;
    }
    static void init()
    {
        p = new singleton();
        ::atexit(destory);
    }
    static void destory()
    {
        if (p)
        {
            delete p;
        }
    }

private:
    static singleton *p;
    static pthread_once_t _once;
    singleton() { cout << "singleton()" << endl; }
    ~singleton() { cout << "~singleton()" << endl; }
};

singleton *singleton::p = nullptr;//懒汉模式
pthread_once_t singleton::_once = PTHREAD_ONCE_INIT;

int main()
{

    singleton *p1 = singleton::getInstance();
    singleton *p2 = singleton::getInstance();
    cout << "p1=" << p1 << endl;
    cout << "p2=" << p2 << endl;
    return 0;
}
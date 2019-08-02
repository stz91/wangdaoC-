#include <iostream>
#include <stdlib.h>
using std::cout;
using std::endl;

class singleton
{
public:
    static singleton *getInstance()
    {
        //在多线程环境下是线程非安全的
        //解决方法:
        //1.加锁
        if (nullptr == p)//多个线程同时进入该判断,会造成单例对象不唯一
        {
            ::atexit(destory);
            p = new singleton();
        }
        return p;
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
    singleton() {}
    ~singleton() { cout << "~singleton" << endl; }
};

//singleton *singleton::p = nullptr;//懒汉模式
singleton *singleton::p = getInstance();//饿汉模式

int main()
{

    singleton *p1 = singleton::getInstance();
    singleton *p2 = singleton::getInstance();
    cout << "p1=" << p1 << endl;
    cout << "p2=" << p2 << endl;
    return 0;
}
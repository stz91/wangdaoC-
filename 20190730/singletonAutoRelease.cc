#include <iostream>
using std::cout;
using std::endl;

class singleton
{
    class autoRelease
    {
    public:
        autoRelease()
        {
            cout << "autoRelease()" << endl;
        }
        ~autoRelease()
        {
            cout << "~autoRelease()" << endl;
            if(p)
            {
                delete p;
            }
        }
    private:
    };

public:
    static singleton *getInstance()
    {
        //在多线程环境下是线程非安全的
        //解决方法:
        //1.加锁
        if (nullptr == p)//多个线程同时进入该判断,会造成单例对象不唯一
        {
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
    static autoRelease _auto;//非静态的数据成员就是单例对象的一部分
    static singleton *p;
    singleton() {}
    ~singleton() { cout << "~singleton" << endl; }
};

//singleton *singleton::p = nullptr;//懒汉模式
singleton::autoRelease singleton::_auto;
singleton *singleton::p = getInstance();//饿汉模式

int main()
{
    singleton *p1 = singleton::getInstance();
    singleton *p2 = singleton::getInstance();
    cout << "p1=" << p1 << endl;
    cout << "p2=" << p2 << endl;
    return 0;
}
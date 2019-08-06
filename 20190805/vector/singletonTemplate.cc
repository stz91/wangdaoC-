#include <iostream>
#include <pthread.h>
using std::cout;
using std::endl;

template <typename T>
class Singleton
{
public:
    template<typename... Args>
    static T *getInstance(Args... args)
    {
        if(_p == nullptr)
        {
            _p = new T(args...);
            atexit(destroy);
        }
        else
        {
            *_p = T(args...);
        }
        return _p;   
    }
    static void destroy()
    {
        if(_p)
        {
            delete _p;
            _p = nullptr;
        }
    }
protected:
    Singleton();
    ~Singleton();
public:
    static T * _p;
};

template <typename T> T* Singleton<T>::_p = nullptr; //恶汉模式

class Point
{
public:
    Point() = default;
    Point(int x, int y)
    : _x(x)
    , _y(y)
    {
        //cout << "Point(int, int)" << endl;
    }
    void print()
    {
        cout << "(" << _x << ", " << _y << ")" << endl; 
    }
private:
    int _x = 0;
    int _y = 0;
};

int main(void)
{
    Point *p3 = Singleton<Point>::getInstance(1, 2);
    Point *p4 = Singleton<Point>::getInstance(2, 3);
    printf("%p\n", p3);
    printf("%p\n", p4);
    p3->print();
    p4->print();
    return 0;
}

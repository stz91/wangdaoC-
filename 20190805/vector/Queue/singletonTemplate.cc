#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class Singleton
{
public:
    static Singleton *getInstance()
    {
        if(_p == nullptr)
        {
            _p = new Singleton();
        }
        else
        {}
        return _p;   
    }
    void destory()
    {
        if(_p)
        {
            delete _p;
        }
    }
private:
    Singleton();
    ~Singleton();
    static Singleton * _p;
};
Singleton<int> * Singleton<int>::_p = nullptr;

int main(void)
{
    return 0;
}
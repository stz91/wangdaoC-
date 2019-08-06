#include <iostream>
using std::cout;
using std::endl;

//      实例化
//函数模板--> 模板函数
//      模板参数推导--> 代码生成器
template<class T>
T add(T x, T y);

template<class T>
T add(T x, T y)
{
    return x + y;
}

int add(int x, int y)
{
    return x * y; 
}

int main(void)
{
    int d1 = 1, d2 = 2;
    cout << "add(d1, d2) = " << add(d1, d2) << endl;
}

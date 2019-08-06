#include <iostream>
using std::cout;
using std::endl;


//模板形参列表可以有存放多个参数的
//模板形参的设置有多个类型
//类型参数
//非类型参数, 常量表达式,整形数据(bool/char/short/int/double)
//
//模板形参可以设置默认值
template <class T1, class T2>
void func(T1 t1, T2 t2)
{
    cout << "t1 = " << t1 << endl;
    cout << "t2 = " << t2 << endl;
}

template <class T, int NUMBER = 10>
T func1(T t)
{
    return NUMBER * t;
}

int main(void)
{
    int d1 = 1;
    double d2 =1.1;
    func(d1, d2);
    cout << func1(d1) << endl;
    return 0;
}

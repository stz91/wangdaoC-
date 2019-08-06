#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

template <typename... Args>
void print(Args... args)
{
    cout << "sizeof...(Args) = " << sizeof...(Args) << endl;
    cout << "sizeof...(args) = " << sizeof...(args) << endl;
}
template <typename T>
void display(T t)
{
    cout << t << endl;
}

template <typename T, typename... Args> //模板参数包
void display(T t, Args... args) //函数参数包
{
    cout << t << " ";
    display(args...);//解包/拆包
}

int main(void)
{
    //print(1, 1.11, 'a', "hello");
    display(1, 1.11, 'a', "hello");
    return 0;
}
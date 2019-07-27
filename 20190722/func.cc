#include <iostream>
using std::cout;
using std::endl;

int num = 1000;
int func1()
{
    int temp = 100;
    return temp;
}

int & func2()
{
    int temp = 200;
    return num;
}//不能返回生命周期小于函数的变量

int main(void)
{
    //func() = 1;
    func2() = 2;
    cout << func2() << endl;
    return 0;
}
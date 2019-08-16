#include <iostream>
#include <functional>
using namespace std;
class A
{
public:
    void fun_3(int k, int m)
    {
        cout << k << " " << m << endl;
    }
};

void fun(int x, int y, int z)
{
    cout << x << " " << y << " " << z << endl;
}

void fun_2(int &a, int &b)
{
    a++;
    b++;
    cout << a << " " << endl;
}

int main()
{
    auto f1 = bind(fun, 1, 2, 3);
    f1();

    auto f2 = bind(fun, placeholders::_1, placeholders::_2, 3);
    f1(1, 2);

    A a;
    auto f5 = bind(&A::fun_3, a, 1, 2);
    f5();

    return 0;
}
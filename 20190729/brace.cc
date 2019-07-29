#include <iostream>
using std::cout;
using std::endl;

class Example
{
public:
    int operator()(int x, int y)
    {
        return x + y;
    }
    int operator()(int x, int y, int z)
    {
        return x + y + z;
    }

    int CallTime() const { return _count; }

private:
    int _count = 0;
};

int main(void)
{
    // 重载了函数调用运算符的类创建的对象,将为函数对象
    Example e1;
    int a = 3, b = 4, c = 5;
    cout << "e1(a, b) = " << e1(a, b) << endl;
    cout << "e1(a, b, c) = " << e1(a, b, c) << endl;
    return 0;
}
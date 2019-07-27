#include <iostream>
using std::cout;
using std::endl;

int add(int a = 0, int b = 0)
{
    return a + b;
}

int main(void)
{
    cout << add(1) << endl;
    return 0;
}
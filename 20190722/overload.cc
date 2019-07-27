#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

int add(int a, int b, int c)
{
    return a + b + c;
}

int add(int a, int b)
{
    return a + b;
}

int main()
{
    cout << add(1, 2) << endl;
    cout << add(1, 2, 3) << endl;
    return 0;
}
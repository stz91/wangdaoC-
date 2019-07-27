#include <iostream>
using std::cout;
using std::endl;

int main()
{
    int num1=10;
    int num2=20;
    const int *p1 = &num1;
    //*p1 = 100;
    p1 = &num2;
    int * const p2 = &num2;
    *p2 = 200;
    //p2 = &num1;

    return 0;
}
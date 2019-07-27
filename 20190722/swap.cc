#include <iostream>
using std::cout;
using std::endl;

void swap1(int * pa, int * pb)
{
    int temp;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
}

void swap2(int & a, int & b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 1, b = 2;
    //swap1(&a, &b);
    swap2(a, b);
    cout << a << b <<endl;
}
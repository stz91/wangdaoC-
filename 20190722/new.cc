#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

int main()
{
    int * p = new int(1);
    cout<<*p<<endl;
    delete p;
    int * p2 = new int[10]();
    for(int index = 0; index <= 10; index++)
    {
        p2[index]=index;
    }
    delete []p2;
    return 0;
}
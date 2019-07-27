#include <iostream>
using std::cout;
using std::endl;

struct test
{
    int & ef;
};

int main(void)
{
    int a=5;
    int & ef=a;
    cout << sizeof(int &) <<endl;
    cout << sizeof(ef) << endl;
    cout << sizeof(test) <<endl;
    return 0;
}
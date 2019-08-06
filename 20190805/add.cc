#include "add.h"
#include <string>
using std::cout;
using std::endl;
using std::string;

template<class T>
T add(T x, T y)
{
    return x + y;
}

template <class T>
T add(T x, T y, T z)
{
    return x + y + z;
}

int main(void)
{
    int d1 = 1, d2 = 2;
    string s1 = "hello", s2 = "world";
    cout << s1 + s2 << endl;
    cout << "add(d1, d2) = " << add(d1, d2) << endl;
    cout << "add(s1, s2) = " << add(s1, s2) << endl;
    return 0;
}

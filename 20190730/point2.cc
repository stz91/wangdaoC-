#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
    Point(int ix = 0, int iy = 0)
        : _ix(ix), _iy(iy)
    {
        cout << "Point(int, int)" << endl;
    }

    operator int()
    {
        cout << "operator int()" << endl;
        return _ix * _iy;
    }

    operator double()
    {
        return _ix * _iy;
    }
    friend std::ostream & operator<<(std::ostream & os, const Point &rhs);

private:
    int _ix;
    int _iy;
};

#if 1
std::ostream & operator<<(std::ostream & os, const Point &rhs)
{
    os << "{" << rhs._ix
        << "." << rhs._iy
        << "}" << endl;
}
#endif

int main(void)
{
    Point pt1(1, 1);
    cout << "pt1" << pt1 << endl;
    return 0;
}
#include <iostream>
#include <cmath>
using std::cout;
using std::endl;

class point;

class line
{
public:
    float distance(const point &lhs, const point &rhs);
};

class point
{
public:
    point()
    : _x(0)
    , _y(0)
    {
        cout << "point()" << endl;
    }
    point(int x, int y)
    : _x(x)
    , _y(y)
    {
        cout << "point(int x, int y)" << endl;
    }
    ~point()
    {
        cout << "~point()" << endl;
    }
    void print() const
    {
        cout << "(" << _x
             << "," << _y
             << ")";
    }
#if 0
    void setLine()
    {

    }
#endif
    //有缘关系时单项的,不具备传递性, 不能继承
    //有缘之成员函数
    friend line;
    friend float line::distance(const point &lhs, const point &rhs);

private:
    int _x, _y;
};
float line::distance(const point &lhs, const point &rhs)
{
    return sqrt((lhs._x - rhs._y) * (lhs._x - rhs._x) +
           (lhs._y - rhs._y) * (lhs._y - rhs._y));
}

int main()
{
    point p1(0,0);
    point p2(10,11);
    p1.print();
    cout << "--->";
    p2.print();
    line l1;
    cout << "的距离 = " << l1.distance(p1,p2) << endl;
    return 0;
}
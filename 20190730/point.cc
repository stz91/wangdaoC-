#include <iostream>
using std::cout;
using std::endl;

class Complex
{

public:
    Complex(double dreal, double dimg)
        : _dreal(dreal), _dimag(dimg)
    {
        cout << "Complex(double dreal, double dimg)" << endl;
    }

    Complex operator+(const Complex &rhs)
    {
        return Complex(_dreal + rhs._dreal, _dimag + rhs._dimag);
    }
    //前置形式
    Complex &operator++()
    {
        ++_dreal;
        ++_dimag;
        return *this;
    }
    //后置形式
    Complex operator++(int)
    {
        Complex tmp((*this));
        ++_dreal;
        ++_dimag;
        return tmp;
    }
    Complex operator+=(Complex &rhs)
    {
        _dreal += rhs._dreal;
        _dimag += rhs._dimag;
        return *this;
    }
    friend bool operator==(Complex &lhs, Complex &rhs);

    //std::ostream & operatot<<(std::ostream)

    friend std::ostream &operator<<(std::ostream &os, const Complex &c1);

    friend class Point;
private:
    double _dreal;
    double _dimag;
};
std::ostream &operator<<(std::ostream &os, const Complex &c1)
{
    os << c1._dreal << " + " << c1._dimag << "i" << endl;
}

bool operator==(Complex &lhs, Complex &rhs)
{
    return (lhs._dreal == rhs._dreal) && (lhs._dimag == rhs._dimag);
}
bool operator!=(Complex &lhs, Complex &rhs)
{
    return !(lhs == rhs);
}

class Point
{
public:
    Point(int ix = 0, int iy = 0)
    : _ix(ix)
    , _iy(iy)
    {
        cout << "Point(int, int)" << endl;
    }
    //explicit //禁止隐式转换
    Point(const Complex &rhs)
    : _ix(rhs._dreal)
    , _iy(rhs._dimag)
    {
        cout << "Point(const Complex &rhs)" << endl;
    }
    friend std::ostream & operator<<(std::ostream & os, const Point &rhs);
private:
    int _ix;
    int _iy;
};

std::ostream & operator<<(std::ostream & os, const Point &rhs)
{
    os << "{" << rhs._ix
        << "." << rhs._iy
        << "}" << endl;
}

void test0()
{
    Point pt1(12, 11);
    cout << "pt1 = " << pt1 << endl;
    Complex c1(1 ,2);
    cout << "c1 = "  << c1 << endl;
    Point pt2 = c1;
    cout << "pt2 = " << pt2 << endl;
}

int main(void)
{
    test0();
    return 0;
}
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
    //explicit //禁止隐式转换
    friend std::ostream &operator<<(std::ostream &os, const Point &rhs);

private:
    int _ix;
    int _iy;
};

std::ostream &operator<<(std::ostream &os, const Point &rhs)
{
    os << "{" << rhs._ix
       << "." << rhs._iy
       << "}";
}
class Complex
{

public:
    Complex(double dreal, double dimg)
        : _dreal(dreal), _dimag(dimg)
    {
        cout << "Complex(double dreal, double dimg)" << endl;
    }

    void display() const
    {
        cout << _dreal << " + " << _dimag << "i" << endl;
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

    //类型转换函数: 讲自定义类型向其他类型转换
    //特点:成员函数
    //    没有返回类型
    //    必须有返回值
    //    一般情况下不要使用,太过变态
    operator int()
    {
        return _dreal;
    }
    operator double()
    {
        return _dreal * _dimag;
    }
    operator Point()
    {
        return Point(_dreal, _dimag);
    }

    friend bool operator==(Complex &lhs, Complex &rhs);

    //std::ostream & operatot<<(std::ostream)

    friend std::ostream &operator<<(std::ostream &os, const Complex &c1);
    friend std::istream &operator>>(std::istream &is, Complex &rhs);

private:
    double _dreal;
    double _dimag;
};

bool operator==(Complex &lhs, Complex &rhs)
{
    return (lhs._dreal == rhs._dreal) && (lhs._dimag == rhs._dimag);
}
bool operator!=(Complex &lhs, Complex &rhs)
{
    return !(lhs == rhs);
}

std::ostream &operator<<(std::ostream &os, const Complex &c1)
{
    os << c1._dreal << " + " << c1._dimag << "i" << endl;
}

int main(void)
{
    Complex c1(1, 2);
    int x = c1;
    double y = c1;
    Point pt1 = c1;
    cout << pt1 << endl;
}
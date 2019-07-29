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
    friend bool operator==(Complex &lhs, Complex &rhs);

    //std::ostream & operatot<<(std::ostream)

    friend std::ostream &operator<<(std::ostream &os, const Complex &c1);
    friend std::istream &operator>>(std::istream & is, Complex &rhs);

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

void readDoublevlue(std::istream & is, double & number)
{
    cout << "pls input a valid double value: " << endl;
    while (is >> number, !is.eof())
    {
        if(is.bad())
        {
            cout << "istream has corrupted!" << endl;
        }
        else if(is.fail())
        {
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "pls input a valid value!" << endl;
            continue;
        }
        break;
    }
    
}

std::istream operator>>(std::istream & is, const Complex &rhs)
{
}

//重载运算副必须是一个类类型或者是枚举类型的操作数
//优先级和结合性时固定的
//不在具备短路求值特性
//不能已造并重载一个不存在的运算符
//尽量不要去重载逻辑运算符
void test1()
{
    Complex v1(1, 2);
    cout << "v1 = ";
    v1.display();
    Complex v2(2, 3);
    cout << "v2 = ";
    v2.display();
    Complex v3 = v1 + v2;
    cout << "v3 = ";
    v3.display();
}

void test2()
{
    int a = 1;
    cout << "(a++) = " << (a++) << endl;
    cout << "a = " << a << endl;
    cout << "(++a) = " << (++a) << endl;
    cout << "a = " << a << endl;
#if 1
    Complex v1(1, 1), v2(2, 2);
    ++v1;
    v1.display();
    v2++;
    (v2++).display();
#endif
}

void test3()
{
    Complex v1(1, 1), v2(2, 2);
    v1 += v2;
    v1.display();
}

void test4()
{
    Complex v1(1, 1), v2(2, 2);
    v1 += v2;
    operator<<(operator<<(cout, "v1 = "), v1);
    //输出流运算副的操作操作要求
}

int main(void)
{
    //test2();
    //test1();
    test4();
    return 0;
}
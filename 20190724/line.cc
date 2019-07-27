#include <iostream>
using std::cout;
using std::endl;

class point
{
public:
    point(int ix, int iy)
    : _ix(ix)
    , _iy(iy)
    {
        cout << "point(int ix, int iy)" << endl;
    }
    point(const point & rhs)
    : _ix(rhs._ix)
    , _iy(rhs._iy)
    {
        cout << "point(const point & rhs)" << endl;
    }
    point & operator=(const point & rhs)
    {
        if(this != &rhs)
        {
            _ix = rhs._ix;
            _iy = rhs._iy;
            cout << "point & operator=(const point & rhs)" << endl;
        }
    }
    void print()
    {  
        cout << '(' << _ix << ',' << _iy << ')';        
    }
private:
    int _ix;
    int _iy;
};

class line
{
public:
    line(int a, int b, int c, int d)
    : _p1(a, b)
    , _p2(c, d)
    {
        cout << "line(int a, int b, int c, int d)" << endl;
    }
    line(const line & rhs)
    : _p1(rhs._p1)
    , _p2(rhs._p2)
    {
        cout << "line(const line & rhs)" << endl;
    }
    void print()
    {
        _p1.print();
        cout << "----->";
        _p2.print();

    }
private:
    point _p1;
    point _p2;
};

int main()
{
    line l1(1,2,3,4);
    l1.print();
    cout << endl;
    return 0;
}
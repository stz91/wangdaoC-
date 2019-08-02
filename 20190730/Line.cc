#include <iostream>
#include "Line.h"
using std::cout;
using std::endl;

class Line::LineImp1
{
    class Point
    {
    public:
        Point(int ix = 0, int iy = 0)
            : _ix(ix), _iy(iy)
        {
            cout << "Point(int, int)" << endl;
        }
        friend std::ostream &operator<<(std::ostream &os, const Point &rhs)
        {
            os << "{" << rhs._ix
               << "." << rhs._iy
               << "}";
        }
        ~Point()
        {
            cout << "~Point()" << endl;
        }
        void Print() const
        {
            cout << "(" << _ix << "," << _iy << ")";
        }

    private:
        int _ix;
        int _iy;
    };
    friend std::ostream &operator<<(std::ostream &os, const LineImp1 &rhs);

public:
    LineImp1(int x1, int y1, int x2, int y2)
        : _pt1(Point(x1, y1)), _pt2(Point(x2, y2))
    {
        cout << _pt1 << endl;
        cout << "LineImp1(int x1, int y1, int x2, int y2)" << endl;
    }
    ~LineImp1()
    {
        cout << "~LineImp1()" << endl;
    }
    void printLine() const;

private:
    Point _pt1;
    Point _pt2;
};

Line::Line(int x1, int y1, int x2, int y2)
    : _lImp1(new LineImp1(x1, y1, x2, y2))
{
    cout << "Line::Line(int x1, int y1, int x2, int y2)" << endl;
}

Line::~Line()
{
    if (_lImp1)
    {
        delete _lImp1;
    }
    cout << "Line::~Line()" << endl;
}

void Line::printLine()
{
    _lImp1->printLine();
}
void Line::LineImp1::printLine() const
{
    _pt1.Print();
    cout << "---->";
    _pt2.Print();
    cout << endl;
}

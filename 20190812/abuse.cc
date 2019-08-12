#include <iostream>
#include <memory>
using namespace std;

class Point
: public enable_shared_from_this<Point>
{
    public:
    Point(int ix, int iy)
    : _ix(ix)
    , _iy(iy)
    {
        cout << "Point(int, int)" << endl;
    }

    void Print() const
    {
        cout << "(" << _ix << ", " << _iy << ")" << endl;
    }
    // Point * addPoint(Point * pt)
    shared_ptr<Point> addPoint(Point *pt)
    {
        _ix += pt->_ix;
        _iy += pt->_iy;
        //return (shared_ptr<Point>)this;
        return shared_from_this();
    }
    ~Point()
    {
        cout << "~Point()" << endl; 
    }
private:
    int _ix;
    int _iy;
};

void test0()
{
    Point *pt = new Point(1, 2);
    unique_ptr<Point> up1(pt);
    unique_ptr<Point> up2(pt);
}

void test1()
{
    Point *pt = new Point(1, 2);
    shared_ptr<Point> sp1(pt);
    shared_ptr<Point> sp2(pt);
}

void test2()
{
    shared_ptr<Point> sp1(new Point(1, 2));
    shared_ptr<Point> sp2(new Point(3, 2));

    sp2.reset(sp1.get());
}

void test3()
{
    cout << ">>test3()" << endl;
    shared_ptr<Point> sp1(new Point(1, 2));
    shared_ptr<Point> sp2(new Point(3, 2));   

    shared_ptr<Point> sp3(sp1->addPoint(sp2.get()));
    cout << "sp3'use_count = " << sp3.use_count() << endl; 
}

int main()
{
    // test0();
    test1();
    // test3();
    return 0;
}
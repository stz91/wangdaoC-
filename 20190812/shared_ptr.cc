#include <iostream>
#include <memory>

using namespace std;

class Point
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
    shared_ptr<Point> sp(new Point(1, 2));
    (*sp).Print();
    sp->Print();
    cout << "sp' use_count = " << sp.use_count() << endl;

    shared_ptr<Point> sp2(sp);
    cout << "sp' use_coout = " << sp.use_count() << endl;
    cout << "sp'2 use_count = " << sp2.use_count() << endl;
    (*sp).Print();
    sp->Print();

    (*sp).Print();
    sp->Print();
}

int main()
{
    test0();
    return 0;
}
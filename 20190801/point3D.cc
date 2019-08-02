#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
    Point(int ix = 0, int iy = 0)
    : _ix(ix)
    , _iy(iy)
    {
        cout << "Point(int ix = 0, int iy = 0)" << endl;
    }
    void display() const
    {
        cout << "(" << _ix << "," << _iy << ")" << endl;
    }
protected:
    int getX()
    {
        return _ix;
    }
    int getY()
    {
        return _iy;
    }
private:
    int _ix;
    int _iy;
};

class point3D
: public Point
{
public:
    point3D(int ix = 0, int iy = 0, int iz = 0)
    : _iz(iz)
    , Point(ix, iy) //在这一步对_ix和_iy进行了初始化
    {
        cout << "point3D(int ix = 0, int iy = 0, int iz = 0)" << endl;
    }
    void Print() //加const,就只能调用const函数
    {
        cout << "(" << getX() << "," << getY() << "," << _iz << ")" << endl;
    }

private:
    int _iz;
};

void test0()
{
    point3D p1(1, 2, 3);
    p1.display();
    p1.Print();
}

int main(void)
{
    test0();
    return 0;
}
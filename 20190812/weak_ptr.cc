#include <iostream>
#include <memory>

using namespace std;

class Point
{
public:
    Point(int ix, int iy)
        : _ix(ix), _iy(iy)
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

int main()
{
    weak_ptr<Point> wp;
    {
        shared_ptr<Point> sp(new Point(1, 2));
        wp = sp;

        cout << "sp's use_count = " << sp.use_count() << endl;
        cout << "wp's use_count = " << wp.use_count() << endl;
        cout << "wp's expired = " << wp.expired() << endl; //检查引用计数是否被删除

        shared_ptr<Point> sp2 = wp.lock();
        cout << "sp's use_count = " << sp.use_count() << endl;
        if (sp2)
        {
            cout << "*sp2 = ";
            sp2->Print();
            cout << "weak_ptr 提升成功" << endl;
        }
        else
        {
            cout << "weak_ptr 提升失败" << endl;
        }
    }

    //weak_ptr知道所托管的资源是否还存在，但不能直接访问
    cout << "wp's expired = " << wp.expired() << endl;
    shared_ptr<Point> sp2 = wp.lock();
    if (sp2)
    {
        cout << "*sp2 = ";
        sp2->Print();
        cout << "weak_ptr 提升成功" << endl;
    }
    else
    {
        cout << "weak_ptr 提升失败" << endl;
    }
    return 0;
}

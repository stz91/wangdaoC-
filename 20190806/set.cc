#include <iostream>
#include <set>
#include <cmath>

using namespace std;

template <class Container>
void display(const Container &c)
{
    typename Container::const_iterator cit = c.begin();
    while(cit != c.end())
    {
        cout << *cit << " ";
        ++cit;
    }
    cout << endl;
}

void test0()
{
    set<int> numbers;
    numbers.insert(1);
    numbers.insert(2);
    numbers.insert(3);
    display(numbers);
}

void test1()
{
    int arr[10] = {3,4,5,6,5,7,6,6,7,4};

    set<int> numbers(arr, arr + 10);
    display(numbers);
    //放入set的元素无法进行修改只能删除

    std::pair<set<int>::iterator, bool> ret = numbers.insert(3);
    if(ret.second)
    {
        cout << "添加元素成功!" << endl;
        cout << *ret.first << endl;
    }
    else
    {
        cout << "set中已有相同元素,插入失败!" << endl;
        cout << *ret.first << endl;
    }
    //set容器可以用来去重的
    if(numbers.count(3))
    {
        cout << "查找元素成功!" << endl;
    }
    else
    {
    cout << "set没有该元素" << endl;
    }

    auto it = numbers.find(3);
    if(it == numbers.end())
    {
        cout << "set中没有该元素" << endl;
    }
    else
    {
        cout << "查找元素成功" << endl;
        cout << *it << endl;
    }
}

//红黑树的5个特性
//每个节点非红即黑
//根节点黑色
//每个叶子节点都是黑色
//如果一个节点是红色,则它的节点必须是黑色的
//从一个节点到该节点的子孙节点的所有路径上包含想同数目上的黑节点

void test2()
{
    std::pair<int, string> p(1, "深圳");
    cout << p.first << " ---> " << p.second << endl;
}

class Point
{
public:
    Point() = default;
    Point(int x, int y)
    : _x(x)
    , _y(y)
    {
        //cout << "Point(int, int)" << endl;
    }
    void print()
    {
        cout << "(" << _x << ", " << _y << ")" << endl; 
    }
    int getInstance() const
    {
        return (_x * _x + _y + _y);
    }
    friend std::ostream &operator<<(std::ostream &os, const Point &rhs)
    {
        os << "(" << rhs._x << ", " << rhs._y << ")";
        return os;
    }
private:
    int _x = 0;
    int _y = 0;
};

bool operator<(const Point &lhs, const Point &rhs)
{
    return lhs.getInstance() < rhs.getInstance();
}

bool operator>(const Point &lhs, const Point &rhs)
{
    return lhs.getInstance() > rhs.getInstance();
}

struct Comparator
{
    bool operator()(const Point &lhs, const Point &rhs) const
    {
        return lhs.getInstance() < rhs.getInstance();
    }
};

void test3()
{
    //set<Point, std::greater<Point>> points{
    set<Point, Comparator> points{
        Point(1, 2),
        Point(3, 3),
        Point(0, 0)
    };
    display(points);
}


int main(void)
{
    //test0();
    //test1();
    //test2();
    test3();
    return 0;
}
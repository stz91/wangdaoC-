#include <cmath>
#include <iostream>
#include <functional>
using namespace std;

// typedef (void*)

//Figure是个具体类
//
//面向对象:  继承 + 虚函数　　　不够灵活，对后续的版本造成二进制兼容性问题
//
//基于对象(std::function + std::bind虚函数的位置)
class Figure
{
public:
    using DisplayCallback = function<void()>;
    using AreaCallback = function<void()>;

    void setDisplayCallback(const DisplayCallback &cb)
    {
        _displayCb = cb;
    }
    void setAreaCallback(const AreaCallback &cb)
    {
        _areaCb = cb;
    }
    void handleDisplayCallback()
    {
        if (_displayCb)
            _displayCb();
    }

    double handleAreaCallback()
    {
        if (_areaCb)
            _areaCb();
    }

private:
    function<void()> _displayCb;
    function<void()> _areaCb;
};

void display(Figure fig)
{
    fig.handleDisplayCallback();
    cout << "的面积是:" << fig.handleAreaCallback() << endl;
}

class Rectangle
{
public:
    Rectangle(double length, double width)
        : _length(length), _width(width)
    {
        cout << "Rectangle()" << endl;
    }
    void display() const
    {
        cout << "rectangle";
    }
    double area() const
    {
        return _length * _width;
    }

private:
    double _length;
    double _width;
};

class Circle
{
public:
    Circle(double radius)
        : _radius(radius)
    {
        cout << "Circle()" << endl;
    }
    void print() const
    {
        cout << "circle";
    }
    double calcArea() const
    {
        return 3.14159 * _radius * _radius;
    }
private:
    double _radius;
};

class Triangle
{
public:
    Triangle(double a, double b, double c)
        : _a(a), _b(b), _c(c)
    {
        cout << "Triangle()" << endl;
    }
    void show() const
    {
        cout << "triangle";
    }
    double getArea() const
    {
        double p = (_a + _b + _c) / 2;
        return sqrt(p * (p - _a) * (p - _b) * (p - _c));
    }

private:
    double _a;
    double _b;
    double _c;
};

class Cube
{
public:
    Cube(double a)
        : _a(a)
    {
        cout << "Cube()" << endl;
    }
    void display() const
    {
        cout << "cube";
    }
    double area() const
    {
        return 6 * _a * _a;
    }

private:
    double _a;
};



int main()
{
    Figure figure;

    Rectangle rectangle(3, 4);
    Circle circle(10);
    Triangle triangle(3, 4, 5);

    figure.setDisplayCallback(bind(&Rectangle::display, &rectangle));
    figure.setAreaCallback(bind(&Rectangle::area, &rectangle));
    display(figure);
}
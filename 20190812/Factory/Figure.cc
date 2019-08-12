#include <math.h>
#include <iostream>

using namespace std;

class Figure
{
public:
    virtual void display() const = 0;
    virtual double area() const = 0;
};

void display(Figure *fig)
{
    fig->display();
    cout << "的面积是: " << fig->area() << endl;
}

class Rectangle
: public Figure
{
public:
    Rectangle(double length, double width)
        : _length(length), _width(width)
    {
        cout << "Rectangle(double, double)" << endl;
    }

    ~Rectangle()
    {
        cout << "~Rectangle()" << endl;
    }

    void display() const
    {
        cout << "Rectangle ";
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
: public Figure
{
public:
    Circle(double radius)
    : _radius(radius)
    {
        cout << "Circle()" << endl;
    }
    void display() const
    {
        cout << "circle";
    }
    double area() const
    {
        return 3.14159 * _radius * _radius;
    }
private:
    double _radius;
};

class Triangle
: public Figure
{
public:
    Triangle(double a, double b, double c)
    : _a(a)
    , _b(b)
    , _c(c)
    {
        cout << "Triangle()" << endl;
    }
    void display() const
    {
        cout << "triangle";
    }
    double area() const
    {
        double p = (_a + _b + _c) / 2;
        return sqrt(p * (p - _a) * (p - _b) * (p - _c));
    }
private:
    double _a;
    double _b;
    double _c;
};

//静态工厂方法
//缺点：１．不满足单一职责原则
//　    ２.不满足开闭原则

class Factory
{
public:
    static Rectangle createRectangle()
    {
        Rectangle rectangle(3, 4);
        return rectangle;
    }

    static Circle createCircle()
    {
        Circle circle(10);
        return circle;
    }

    static Triangle createTriangle()
    {
        Triangle triangle(3, 4, 5);
        return triangle;
    }
};

int main(void)
{
    Rectangle rectangle = Factory::createRectangle();
    Circle circle = Factory::createCircle();
    Triangle triangle = Factory::createTriangle();

    display(&rectangle);
    display(&circle);
    display(&triangle);
    return 0;
}
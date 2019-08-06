#include <iostream>
using std::cout;
using std::endl;

class Figure
{
public:
    virtual void display() const =0;
    virtual double area() const = 0;
private:
};

void dispaly(Figure * fig)
{
    fig->display();
    cout << "的面积是:" << fig->area() << endl;   
}

class Rectangle
: public Figure
{
public:
    Rectangle(double length, double width)
    : _length(length)
    , _width(width)
    {
        cout << "Rectangle(double length, double width)" << endl;
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
: public Figure
{
public:
    Circle(double radius)
    : _radius(radius)
    {
        cout << "Circle(double radius)" << endl;
    }
    void display() const
    {
        cout << "circle";
    }
    double area() const
    {
        return 3.14 * _radius * _radius;
    }
private:
    double _radius;
};

int main()
{
    Rectangle rectangle(3, 4);
    Circle circle(3);
    rectangle.display();
    cout << rectangle.area() << endl;
    circle.display();
    cout << circle.area() << endl;
    return 0;
}
#include <iostream>
#include <cmath>
using std::cout;
using std::endl;

#define PI 3.14

class Circle
{
public:
    Circle()
        : _radius(0)
    {
        cout << "Circle()" << endl;
    }
    Circle(double r)
        : _radius(r)
    {
        cout << "Circle(double r)" << endl;
    }
    double getArea()
    {
        return PI * _radius * _radius;
    }
    double getPerimeter()
    {
        return 2 * PI * _radius;
    }
    void show()
    {
        cout << "radius = " << _radius << endl;
        cout << "area = " << getArea() << endl;
        cout << "perimeter = " << getPerimeter() << endl;
    }

private:
    double _radius;
};

class Cylinder
    : public Circle
{
public:
    Cylinder(double r, double h)
        : Circle(r), _hight(h)
    {
        cout << "Cylinder(double r, double h)" << endl;
    }
    double getVolume()
    {
        return getArea() * _hight;
    }
    void showVolume()
    {
        cout << "volume = " << getVolume() << endl;
    }

private:
    double _hight;
};

int main()
{
    Circle c1(1.0);
    Cylinder cy1(1.0, 2.0);
    c1.show();
    cy1.showVolume();
}
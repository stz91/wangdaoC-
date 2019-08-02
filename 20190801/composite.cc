#include <iostream>
using std::endl;
using std::cout;

class eye
{
public:
    void look()
    {
        cout << "look()" << endl;
    }
};

class ear
{
public:
    void listen()
    {
        cout << "listen()" << endl;
    }
};

class mouth
{
public:
    void speak()
    {
        cout <<"speak()" << endl;
    }
};

class head //继承方式,设计不合理
: public mouth
, public ear
, public eye
{};

class head2 //组合方式
{
public:
    void listen()
    {
        _ear.listen();
    }
    void look()
    {
        _eye.look();
    }
    void speak()
    {
        _mouth.speak();
    }
private:
    eye _eye;
    mouth _mouth;
    ear _ear;
};

int main()
{
    head2 h2;
    h2.listen();
    h2.look();
    h2.speak();
    return 0;
}
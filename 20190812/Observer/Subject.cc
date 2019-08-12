#include "Subject.h"
#include "Observer.h"
#include <iostream>
#include <algorithm>

using namespace std;

void Ring::attach(Observer * obj)
{
    auto it = find(_obList.begin(), _obList.end(), obj);
    if(it == _obList.end())
    {
        _obList.push_front(obj);
    }
}

void Ring::detach(Observer * obj)
{
    auto it = find(_obList.begin(), _obList.end(), obj);
    if(it != _obList.end())
    {
        _obList.erase(it);
    }
}

void Ring::notify()
{
    for(auto &c:_obList)
    {
        c->update();
    }
}

void Ring::isPressed()
{
    if(!_isAlarming)
    {
        _isAlarming = true;
        notify();
    }
    _isAlarming = false;
}

void Guest::knock(Ring &ring)
{
    cout << ">>>Guest " << _name << " is koncking at the door" << endl;
    ring.isPressed();
}
#pragma once

#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <string>

using namespace std;

class Observer
{
public:
    virtual void update() = 0;
    virtual ~Observer()
    {
        cout << "~Observer()" << endl;
    }
};

class Baby
: public Observer
{
public:
    Baby(const string &name)
    : _name(name)
    {
        cout << "Baby(const string &)" << endl;
    }
    void update()
    {
        ::srand(::clock());
        int number = ::rand() % 10;
        if(number > 70)
        {
            cout << "Baby " << _name << "is sleeping sweetly" << endl;
        }
        else
        {
            cout << "Baby" << _name << "is starting crying loudly" << endl;
        }
    }
private:
    string _name;
};

class Nurse
: public Observer
{
public:
    Nurse(const string &name)
    : _name(name)
    {
        cout << "Nurse(const string &)" << endl;
    }
    void update()
    {
        ::srand(::clock());
        int number = ::rand() % 10;
        if(number > 70)
        {
            cout << "Nurse " << _name << "is awake, and is ready to open the door" << endl;
        }
        else
        {
            cout << "Baby" << _name << "is sleeping sweetly" << endl;
        }
    }
private:
    string _name;  
};


#pragma once

#include <Warriors.h>
using namespace std;

enum Force
{
    red = 0,
    blue
};

class HeadQuarter
{
public:
    HeadQuarter(Force force, int life)
    : _force(force)
    , _life(life)
    {
        cout << "HeadQuarter(Force force, int life)" << endl;
    }
    void warriorBorn();
    ~HeadQuarter()
    {
        cout << "~HeadQuarter()" << endl;
    }
private:
    Force _force;
    int _life;
};

class City
{
private:
    int _number;
};

class WarCraft
{
private:
    HeadQuarter _headQuarter[2];
    City _city[5];
};

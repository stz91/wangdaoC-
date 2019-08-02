#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int redCount = 0;
int blueCount = 0;

enum weapon
{
    sword = 0,
    bomb,
    arrow
};

class Warrior
{
public:
    Warrior(int number, int strength)
    : _number(number)
    , _strength(strength)
    {
        cout << "worrior(int, int)" << endl;
    }
    ~Warrior()
    {
        cout << "~Worrior()" << endl;
    }
private:
    int _number;
    int _strength;
};

class Dragon
: public Warrior
{
public:
    Dragon(int number, int strength)
    : Warrior(number, strength)
    , _weapon(weapon(number % 3))
    , _morale((number + 1) % 3)
    {
        cout << "Dragon(int number)" << endl;
    }
private:
    weapon _weapon;
    float _morale;
};

class Ninja
: public Warrior
{
public:
    Ninja(int number, int strength)
    : Warrior(number, strength)
    , _weapon1(weapon(number % 3))
    , _weapon2(weapon((number + 1) % 3))
    {
        cout << "Ninja(int number)" << endl;
    }
private:
    weapon _weapon1;
    weapon _weapon2;
};

class Iceman
: public Warrior
{
public:
    Iceman(int number, int strength)
    : Warrior(number, strength)
    , _weapon(weapon(number % 3))
    {
        cout << "Iceman(int number)" << endl;
    }
private:
    weapon _weapon;
};

class Wolf
: public Warrior
{};

class Lion
: public Warrior
{
public:
    Lion(int number, int strength)
    : Warrior(number, strength)
    , _morale((number + 1) % 3)
    {
        cout << "Lion(int number)" << endl;
    }
private:
    float _morale;  
};
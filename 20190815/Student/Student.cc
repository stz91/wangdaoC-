#include "Student.h"

Student::Student(size_t id, string name)
: _id(id)
, _name(name)
{}

size_t Student::getId() const
{
    return _id; 
}

string Student::getName() const
{
    return _name;
}
#pragma once

#include "Student.h"

class View
{
protected:
    Student* _student;
public:
    View(Student* student = nullptr)
    : _student(student)
    {}

    void reset(Student * student)
    {
        _student = student;
    }
    virtual void show() const = 0;
};
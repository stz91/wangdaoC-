#pragma once

#include <string>

using std::string;

class Student
{
private:
    size_t _id;
    string _name;
public:
    Student(size_t id, string name);
    size_t getId() const;
    string getName() const;
    void setId(size_t id)
    {
        _id = id;
    }

    void setName(string name)
    {
        _name = name;
    }
};



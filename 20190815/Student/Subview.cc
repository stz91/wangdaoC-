#include "SubView.h"
#include <iostream>

void Subview1::show() const
{
    std::cout << "id = " <<  _student->getId() << std::endl;
    std::cout << "name = " << _student->getName() << std::endl;
}

void Subview2::show() const
{
    std::cout << "id = " <<  _student->getId() << std::endl;
    std::cout << "name = " << _student->getName() << std::endl;
}
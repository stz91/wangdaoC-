#include <iostream>

namespace wd
{
    int number=10;
    void display()
    {
        std::cout << "wd:display()" << std::endl;
    }
}//end of namespace wd

int main(void)
{
    std::cout << "wd:display()" << std::endl;
    wd::display();
    return 0;
}
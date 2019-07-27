#include <iostream>
using std::cout;
using std::endl;

namespace wd
{
int number = 10;
void display()
{
    cout << "wd:display()" << endl;
}
} //end of namespace wd

using wd::display;
using wd::number;
int main(void)
{
    cout << "wd::number = " << number << endl;
    wd::display();
    return 0;
}
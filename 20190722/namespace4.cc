#include <iostream>
using std::cout;
using std::endl;
int number=1;
namespace wd
{
int number = 10;
namespace luo
{
int number = 100;
void display()
{
    cout << "wd::luo::display()" << endl;
}
} // namespace luo
void display(int number)
{
    cout << "number1 = " << number << endl;
    cout << "number2 = " << wd::luo::number << endl;
    cout << "number3 = " << wd::number << endl;
}
} // namespace wd
int main()
{
    using wd::display;
    display(1);
    return 0;
}
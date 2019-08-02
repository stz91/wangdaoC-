#include <iostream>
using std::endl;
using std::cout;

void display()
{
    cout << "display()" << endl;
}

int main()
{
    cout << "endter main function.." << endl;
    ::atexit(display);
    ::atexit(display);

    cout << "exit main function.." << endl;
    return 0;
}
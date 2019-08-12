#include <iostream>
using namespace std;

class Test
{
public:
    void Print()
    {   
        cout << "Print()" << endl;
    }
};

int main(void)
{
    Test * tp = new Test();
    tp->Print();
    return 0;
}
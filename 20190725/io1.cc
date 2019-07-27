#include <iostream>
using namespace std;

void printCinStatus()
{
    cout << "cin badbiy = " << cin.bad() << endl;
    cout << "cin failbit = " << cin.fail() << endl;
    cout << "cin eofbit = " << cin.eof() << endl;
    cout << "cin goodbit = " << cin.good() << endl;
}

void test0()
{
    int number = 0;
    printCinStatus();
    while(cin >> number)
    {
        cout << "number = " << number << endl;
    }
    printCinStatus();
    cin.clear();//重置流的状态
    cin.ignore(100,'\n');
    string s1;
    cin >> s1;
    cout << "s1 = " << s1 << endl;
}

void test1()
{
    int number = 0;
    while(cin >> number , !cin.eof())
    {
        if(cin.bad())
        {
            cout << "cin has corrupted" << endl;
            return;
        }
        else if(cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max,'\0');
            cout << "pls input a valid interger:" << endl;
            continue;
        }
    }
}

int main()
{
    test0();
    return 0;
}
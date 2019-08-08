#include <iostream>
#include <string>

using namespace std;
int main(void)
{
    string s("qwert");
    cout << "s = " << s << endl;
    char &r = s[1];
    char *p = &s[3];
    r = '3';
    *p = '4';
    cout << s << endl;
    s = "zxcvbnm";
    cout << "s = " << s << endl;
    r = '2';
    *p ='4';
    cout << s << endl;
}
#include <iostream>
#include <string>
using std::endl;
using std::cout;

int main()
{
    std::string s1 = "helloworld";
    char &a = s1[0];
    char *b = &s1[1];
    s1 = "nihaoworld";
    a = 'a';
    *b = 'c';
    cout << s1 << endl;
}
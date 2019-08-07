#include <iostream>
#include <sstream>
#include <string>

using namespace std;
int main()
{
    string line("hello i am your father");
    istringstream inWord(line);
    string word;
    while(inWord >> word)
    {
        cout << word << endl;
    }
    return 0;
}
#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
#include <fstream>

using namespace std;


int main()
{
    ifstream file;
    file.open("test.txt");
    if(!file)
    {
        cout << "open error" << endl;
        return -1;
    }
    map<string, int> word_count;
    string word;
    while (file >> word)
    {
        ++word_count[word];
    }

    map<string, int>::iterator iter;
    for (iter = word_count.begin(); iter != word_count.end(); iter++)
    {
        cout << '|' << iter->first << "--->" << iter->second << endl;
    }
    return 0;
}
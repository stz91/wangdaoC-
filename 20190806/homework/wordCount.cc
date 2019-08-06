#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
#include <fstream>
#include <time.h>
#include <iomanip>

using namespace std;

int isLetter(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    else
        return 0;
}

void lineDeal(string line, map<string, int> &word_count)
{
    string word;
    int i = 0;
    for (i = 0; i < line.size(); i++)
    {
        if (isLetter(line[i]))
            word.push_back(line[i]);
        else if (line[i] == ' ')
        {
            if (word.size() != 0)
            {
                ++word_count[word];
            }
            word.clear();
        }
    }
    if (word.size() != 0)
        ++word_count[word];
}

int main()
{
    time_t begin, end;
    ifstream file;
    fstream file2;
    file2.open("dictory.txt", ios::out);
    file.open("The_Holy_Bible.txt");
    if (!file || !file2)
    {
        cout << "open error" << endl;
        return -1;
    }
    map<string, int> word_count;
    string line;
    begin = time(nullptr);
    while (getline(file, line))
    {
        lineDeal(line, word_count);
    }
    map<string, int>::iterator iter;
    for (iter = word_count.begin(); iter != word_count.end(); iter++)
    {
        file2 << setiosflags(ios::left) << "|   " << setw(20) << iter->first << setiosflags(ios::right) << setw(10) << iter->second << "   |" << endl;
    }
    end = time(nullptr);
    cout << "used time is " << end - begin << endl;
    file.close();
    file2.close();
    return 0;
}
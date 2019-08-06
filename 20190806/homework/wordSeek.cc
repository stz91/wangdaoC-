#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <set>

using namespace std;

int isLetter(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    else
        return 0;
}

void lineDeal(string line, map<string, set<int>> &dict, map<string, int> &dictCount, int lineNumber)
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
                dict[word].insert(lineNumber);
                ++dictCount[word];
            }
            word.clear();
        }
    }
    if (word.size() != 0)
    {
        dict[word].insert(lineNumber);
        ++dictCount[word];
    }
}

class TextQuery
{
public:
    void readFile(const string filename)
    {
        _file.open(filename);
        string line;
        int lineNumber = 1;
        while (getline(_file, line))
        {
            lineDeal(line, _dictLine, _dictCount, lineNumber);
            ++lineNumber;
        }
    }
    void display(const set<int> &c)
    {
        //文件流到文件尾要先clear一下
        _file.clear();
        _file.seekg(0);
        string line = "nihao";
        int lineNumber = 0;
        set<int>::const_iterator cit = c.begin();
        while (cit != c.end())
        {
            while (lineNumber < *cit)
            {
                line.clear();
                getline(_file, line);
                ++lineNumber;
            }
            cout << "(line " << *cit << ")";
            cout << line << endl;
            ++cit;
        }
    }
    void query(const string &word)
    {
        cout << word << " occurs " << _dictCount[word] << " times." << endl;
        display(_dictLine[word]);
    }

private:
    ifstream _file;
    map<string, set<int>> _dictLine;
    map<string, int> _dictCount;
};

int main(int args, char *argv[])
{
    if (args != 2)
    {
        cout << "./a.out filename" << endl;
        return -1;
    }
    TextQuery tq;
    string queryWord("link");
    tq.readFile(argv[1]);
    while (cout << "please input word:" && cin >> queryWord)
    {
        if (queryWord == "quit")
        {
            break;
        }
        tq.query(queryWord);
        queryWord.clear();
    }
    return 0;
}
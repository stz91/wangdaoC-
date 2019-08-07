#include <iostream>
#include <string>
#include <set>

using namespace std;

class LadderLength
{
public:
    LadderLength()
    : _length(0)
    {
        cout << "ladderLength()" << endl;
    }
    ~LadderLength()
    {
        cout << "~LadderLength()" << endl;
    }
    int ladderLength(string beginWord, string endWord, const set<string> &wordList)
    {
        auto itBeg = wordList.find(beginWord);
        auto itEnd = wordList.find(endWord);
        if(itBeg == wordList.end() || itEnd == wordList.end())
        {
            return _length;
        }

    }
private:
    int _length;
    bool wordJudge(string s1, string s2)
    {
        int count = 0;
        if(s1.size() != s2.size())
        {
            return false;
        }
        for(int idx = 0; idx < s1.size(); ++idx)
        {
            if()
        }
    }
};

int main(void)
{
    return 0;
}
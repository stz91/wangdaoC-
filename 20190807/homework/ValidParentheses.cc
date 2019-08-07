#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class ValidParentheses
{
public:
    ValidParentheses(string s1)
    : _string(s1)
    {
        cout << "ValidParentheses(string)" << endl;
    }
    bool judge()
    {
        for(int idx = 0; idx < _string.size(); ++idx)
        {
            if(_string[idx] == '(' || _string[idx] == '[' ||\
            _string[idx] == '{')
            {
                _stack.push(_string[idx]);
            }
            else if(_string[idx] == ')')
            {
                if(_stack.empty())
                {
                    return false;
                }
                if(_stack.top() != '(')
                {
                    return false;
                }
                else
                {
                    _stack.pop();
                    continue;
                }
            }
            else if(_string[idx] == ']')
            {
                if(_stack.empty())
                {
                    return false;
                }
                if(_stack.top() != '[')
                {
                    return false;
                }
                else
                {
                    _stack.pop();
                    continue;
                }
            }else if(_string[idx] == '}')
            {
                if(_stack.empty())
                {
                    return false;
                }
                if(_stack.top() != '{')
                {
                    return false;
                }
                else
                {
                    _stack.pop();
                    continue;
                }
            }
        }
        if(_stack.size() != 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    ~ValidParentheses()
    {
        cout << "~ValidParentheses()" << endl;
    }
private:
    string _string;
    stack<char> _stack;
};

int main(void)
{
    ValidParentheses vp("{()}");
    if(vp.judge())
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}
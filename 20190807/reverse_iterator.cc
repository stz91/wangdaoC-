#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main(void)
{
    vector<int> numbers{1, 2, 3, 4, 5};
    vector<int>::reverse_iterator rit = numbers.rbegin();
    while(rit != numbers.rend())
    //适配器模式，重载运算符已满足操作
    {
        cout << *rit << " ";
        ++rit;
    }
    cout << endl;
    return 0;
}
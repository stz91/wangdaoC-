#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

void test0()
{
    vector<int> numbers{5, 3, 1, 2, 66, 7, 1, 66, 8, 9, 66};
    copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    //remove是没有删除元素的
    remove(numbers.begin(), numbers.end(), 66);
    copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}
void test1()
{
    vector<int> numbers;
    numbers.push_back(1);
    bool flag = true;

    auto it = numbers.begin();
    for(; it != numbers.end(); ++it)
    {
        cout << *it << " ";
        if(flag)
        {
            numbers.push_back(2);
            it = numbers.begin();
            flag = false;
        }    
    }
}

int main(void)
{
    test1();
}
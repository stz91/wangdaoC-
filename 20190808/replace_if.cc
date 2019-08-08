#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

bool compare(int number)
{
    return number > 3;
}

int main()
{
    vector<int> numbers{1, 2, 3, 4, 5, 6};
    less<int> lt;
    greater<int> gt;

    //std::bind1st, std::bind2nd都是用来提前给函数绑定参数的
    replace_if(numbers.begin(), numbers.end(), bind2nd(lt, 3),  7);
    copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}
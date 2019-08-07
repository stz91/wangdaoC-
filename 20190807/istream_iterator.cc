#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;


int main(void)
{
    vector<int> numbers;
    istream_iterator<int> isi(cin);

    // int number;
    // cin >> number;
    // numbers.push_back(number);
    //copy(isi, istream_iterator<int>(), numbers.begin());
    //begin, end 是用来遍历元素的
    //这里需要使用插入迭代器
    copy(isi, istream_iterator<int>(), back_inserter(numbers));
    copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
    vector<int> numbers {1, 2, 3, 4, 5};
    auto it = find(numbers.begin(), numbers.end(), 3);
    cout << "*it = " << *it << endl;
    //为了提高查找速度，可以先排序，在进行查找
    //std::sort默认情况下，按升序方式进行排序
    sort(numbers.begin(), numbers.end(), greater<int>());
    copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));

    it = lower_bound(numbers.begin(), numbers.end(), 3, greater<int>());
    cout << *it << endl;
}
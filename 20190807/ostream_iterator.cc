#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main(void)
{
    vector<int> numbers{1,2,3,4,5};


    //采用适配器设计模式
    //ostream_iterator　模拟迭代器的功能
    ostream_iterator<int> osi(cout, "＊");
    copy(numbers.begin(), numbers.end(), osi);
    cout << endl;
    return 0; 
}
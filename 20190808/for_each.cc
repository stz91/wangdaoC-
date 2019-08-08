#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

void display(int &number)
{
    ++number;
    cout << number << endl;
}

void test0()
{
    vector<int> numbers{1, 2, 3, 4, 5};
    //for_each(numbers.begin(), numbers.end(), display);

    //lambda　表达式
    for_each(numbers.begin(), numbers.end(), [&numbers](int number){
        cout << number << " "; 
        cout << "numbers.size() = " << numbers.size() << endl;
    });
    cout << endl;
    copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main(void)
{
    test0();
}
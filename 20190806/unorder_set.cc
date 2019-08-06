#include <iostream>
#include <unordered_set>
using namespace std;

template <class Container>
void display(const Container &c) 
{
    for(auto &elem: c)
    {
        cout << elem << " ";
    }
    cout << endl;
}

void test0()
{
    int array[10] = {8, 7, 1, 2, 5, 9, 0, 8, 7, 3};
    unordered_set<int> numbers(array, array + 10);
    display(numbers);

    auto it = numbers.begin();
    cout << *it << endl;
    ++it;//前向访问迭代器,只能前向遍历
    cout << *it << endl;

    auto it2 = numbers.find(11);
    if(it2 != numbers.end())
    {
        cout << *it2 << endl;
    }
    else
    {
        cout << "查找元素失败" << endl;
    }   
}

void test3()
{
}

int main(void)
{
    test0();
}
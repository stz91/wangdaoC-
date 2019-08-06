#include <iostream>
#include <vector>
#include <list>
using namespace std;

template <class Container>
void display(const Container &c)
{
    typename Container::const_iterator cit = c.begin();
    for(;cit != c.end(); ++cit)
        cout << *cit << " ";
    cout << endl;
}

struct Greater
{
    bool operator()(const int &lhs, const int &rhs)
    {
        return lhs > rhs;
    }
};

int main(void)
{
    list<int> numbers1{5, 1, 10, 3, 8};
    numbers1.sort();
    Greater g1;
    numbers1.sort(g1);
    display(numbers1);
    return 0;
}
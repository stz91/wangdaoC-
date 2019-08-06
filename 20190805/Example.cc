#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

class Example
{
public:
    Example(int size)
    : _size(size)
    , _data(new int[size]())
    , _cnt(0)
    {}

    template <class Iterator>
    void setData(Iterator beg, Iterator end)
    {
        int _cnt = 0;
        while (beg != end && _cnt < _size)
        {
            _data[_cnt] = *beg;
            ++_cnt;
            ++beg;
        }
        
    }
    void display() const
    {
        for(int idx = 0; idx != _cnt; ++idx)
        {
            cout << _data[_cnt] << " ";
        }
        cout << endl;
    }
private:
    int _size;
    int _cnt;
    int *_data;
};

int main()
{
    vector<int> numbers(10, 1);
    Example e(10);
    e.setData(numbers.begin(), numbers.end());
    e.display();
}
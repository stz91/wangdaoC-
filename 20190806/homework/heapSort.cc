#include <iostream>
#include <vector>
using namespace std;

template <typename T, typename Compare = std::less<T>>
class HeapSort
{
public:
    HeapSort(const vector<T> &array)
    {
        _array.assign(array.begin(), array.end());
    }
    void sort(comp)
    {
        printArray();
        vector<T> array;
        for(int i = _array.size() - 1; i >= 0; --i)
        {
            array.push_back(_array[0]);
            swap(_array[0], _array[i]);
            _array.pop_back();
            downElement(0, comp);
        }
        printArray(array);
        _array.assign(array.begin(), array.end());
    }
    void printArray(const vector<T>& array)
    {
        for(auto iter:array)
        {
            cout << *iter << " ";
        }
        cout << endl;
    }

private:
    vector<T> _array;

    void creatHeap(Compare comp)
    {
        for(int i = _array.size() / 2 - 1; i > 0; --i)
        {
            downElement(i, comp);
        }
    }
    void downElement(int a_elem, Compare comp)
    {
        int min;
        int index = a_elem;
        while (index * 2 + 1 < _array.size())
        {
            min = index * 2 + 1;
            if (index * 2 + 2 < _array.size())
            {
                if (comp(_array[index * 2 + 2], _array[min]))
                {
                    min = index * 2 + 2;
                }
            }
            if(comp(_array[index], _array[min]))
            {
                break;
            }
            else
            {
                {
                    swap(_array[min], array[index]);
                    index = min;
                }
            }
            
        }
    }
};

int main(void)
{
    vector<int> array{3, 6, 2, 8, 5, 4, 1};
    HeapSort<int> heap(array);
}
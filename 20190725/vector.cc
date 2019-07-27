#include <iostream>
#include <string>
#include <vector>
using namespace std;

void display(vector<int> & vec)
{
    cout << "vec's size = " << vec.size() << endl;
    cout << "vec's capacity = " <<vec.capacity() << endl;
}
//vector底层实现,扩容的测略
//三个指针:
//_start, _finesh, _end_of_storage
//开辟一个新空间,将字符拷贝,元空间回收

void test()
{
    int arr[10] = {0};
    vector<int> vec;
    vec.reserve(1000);
    display(vec);
    cout << "sizeof(vec) = " <<sizeof(vec) << endl;

    vec.push_back(1);
    display(vec);

}

int main()
{
    test();
    return 0;
}
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void test0()
{
    vector<int> numbers{2, 3, 4, 5, 6, 7, 8, 9};
    priority_queue<int> que(numbers.begin(), numbers.end());
    while (!que.empty())
    {
        cout << que.top() << " ";
        que.pop();
    }
    cout << endl;
}

void test()
{
    //底层实现:堆排序
    //默认情况下,采用的是小于符号的比较方式
    //的到的序列是一个降序序列  ==>大顶堆
    //
    //

    priority_queue<int> que;
    vector<int> numbers{5, 2, 3, 4, 5, 6, 7, 8, 9};
    for (size_t idx = 0; idx != numbers.size(); ++idx)
    {
        que.push(numbers[idx]);
        cout << "当前队列中优先级最高的元素是" << que.top() << endl;
    }
    while (!que.empty())
    {
        cout << que.top() << " ";
        que.pop();
    }
    cout << endl;
}

void test2()
{
    priority_queue<Point, vector<Point>, Comparator> que();
}

int main(void)
{
    //test0();
    test();
}

//排序算法
//外部排序

//内部排序
    // 八大排序算法:
    // 冒泡排序
    // 快速排序
    // 插入排序
    // 希尔排序
    // 选择排序
    // 堆排序,可以做海量数据的处理
    // 归并排序
    // 基数排序
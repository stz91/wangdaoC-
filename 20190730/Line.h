#pragma once

#include <iostream>
using std::cout;
using std::endl;

//PIMPL设计模式
//
//作用
// 1.实现信息隐藏
// 2,降低编译依赖
// 3.只要接口不变(头文件肯定不变),实现可以随便改造,可以以一个最小的代价完成哭的平滑升级
class Line
{
    class LineImp1;

public:
    Line(int, int, int, int);
    ~Line();
    void printLine();

private:
    LineImp1 *_lImp1;
};

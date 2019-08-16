#pragma once

#include "Thread.h"

namespace wd
{
class TaskQueue;
class Consumer
{
public:
    Consumer(TaskQueue &);
    void fun();
private:
    TaskQueue & _taskQue;
};
}// end of namespace wd
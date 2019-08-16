#pragma once

#include "Thread.h"

namespace wd
{
class TaskQueue;
class Producer
{
public:
    Producer(TaskQueue & taskQue);
    void fun();
private:
    
    TaskQueue & _taskQue;
};
}// end of namespace wd
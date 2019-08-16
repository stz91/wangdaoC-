#pragma once

#include "Thread.h"

namespace wd
{
class TaskQueue;
class Producer
: public Thread
{
public:
    Producer(TaskQueue & taskQue);
private:
    void fun() override;
    TaskQueue & _taskQue;
};
}// end of namespace wd
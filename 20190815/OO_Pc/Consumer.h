#pragma once

#include "Thread.h"

namespace wd
{
class TaskQueue;
class Consumer
: public Thread
{
public:
    Consumer(TaskQueue &);
private:
    void fun() override;
    TaskQueue & _taskQue;
};
}// end of namespace wd
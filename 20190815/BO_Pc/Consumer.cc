#include "Consumer.h"
#include "TaskQueue.h"

#include <unistd.h>
#include <iostream>

using namespace std;

namespace wd
{
Consumer::Consumer(TaskQueue & taskQue)
:   _taskQue(taskQue)
{}

void Consumer::fun()
{
    int cnt = 20;
    while(--cnt)
    {
        int number = _taskQue.pop();
        cout << ">> consumer thread " << pthread_self()
            << " consume a number = " << number << endl;
        ::sleep(1);
    }
}
}
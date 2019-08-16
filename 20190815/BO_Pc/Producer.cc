#include "Producer.h"
#include "TaskQueue.h"

#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

namespace wd
{
Producer::Producer(TaskQueue & taskQue)
: _taskQue(taskQue)
{}

void Producer::fun()
{
    int cnt = 20;
    ::srand(::clock());
    while(--cnt)
    {
        int number = ::rand() % 100;
        _taskQue.push(number);
        cout << ">> producer thread " << pthread_self()
            << " produce a number = " << number << endl;
        ::sleep(1);
    }
}
}// end of namespace wd
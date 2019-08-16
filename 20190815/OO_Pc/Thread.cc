#include "Thread.h"

namespace wd
{
Thread::~Thread()
{
    if(_isRunning)
    {
        pthread_detach(_pthid);
    }
}

void Thread::start()
{
    pthread_create(&_pthid, nullptr, threadFunc, this);
    _isRunning = true;
}

void *Thread::threadFunc(void *arg)
{
    Thread * pthread = static_cast<Thread*>(arg);
    if(pthread)
        pthread->fun();
    return nullptr;
}
void Thread::join()
{
    if(_isRunning)
    {
        pthread_join(_pthid, nullptr);
        _isRunning = false;
    }
}

}//end of namespace wd
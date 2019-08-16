#pragma once

#include <pthread.h>
#include "Noncoptable.h"

namespace wd
{
class Thread
: public Noncopyable
{
private:
    pthread_t _pthid;
    virtual void fun() = 0;
    bool _isRunning;
public:
    Thread()
    : _pthid(0)
    , _isRunning(false)
    {}
    ~Thread();
    void start();
    void join();
    static void *threadFunc(void*);
};
}//end of namespace wd;
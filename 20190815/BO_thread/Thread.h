#pragma once

#include <pthread.h>
#include <functional>
#include "Noncoptable.h"

namespace wd
{
class Thread
: public Noncopyable
{
public:
    using ThreadCallback = std::function<void()>;
private:
    pthread_t _pthid;
    ThreadCallback _cb;
    bool _isRunning;
public:   
    Thread(ThreadCallback && cb)
    : _pthid(0)
    , _isRunning(false)
    , _cb(std::move(cb))
    {}
    
    ~Thread();
    void start();
    void join();
    static void *threadFunc(void*);
};
}//end of namespace wd;
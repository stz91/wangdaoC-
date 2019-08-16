#pragma once

#include <pthread.h>
#include "Noncoptable.h"

#include <functional>

namespace wd
{
class Thread
: public Noncopyable
{
    using ThreadCallback = std::function<void()>;
private:
    pthread_t _pthid;
    bool _isRunning;
    ThreadCallback _cb;
public:
    Thread(ThreadCallback cb)
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
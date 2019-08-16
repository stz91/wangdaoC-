#pragma once

#include <pthread.h>
#include "Noncoptable.h"

namespace wd
{
class MutexLock;
class Condition
: public Noncopyable
{
public:
    Condition(MutexLock & mutex);

    ~Condition();

    void wait();
    void notify();
    void notifyall();
private:
    pthread_cond_t _cond;
    MutexLock & _mutex;
};
}
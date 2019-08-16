#include "TaskQueue.h"

namespace wd
{
TaskQueue::TaskQueue(size_t size)
: _queSize(size)
, _mutex()
, _notEmpty(_mutex)
, _notFull(_mutex)
{}

bool TaskQueue::empty() const
{
    return _que.size() == 0;
}

bool TaskQueue::full() const
{
    return _que.size() == _queSize;
}

void TaskQueue::push(ElemType elem)
{
    MutexLockGuard autolock(_mutex);
    while(full()) // 使用while()是为了防止虚假(异常)唤醒
    {
        _notFull.wait();
    }

    _que.push(elem);
    _notEmpty.notify();
}

ElemType TaskQueue::pop()
{
    MutexLockGuard autolock(_mutex);
    while(empty())
    {
        _notEmpty.wait();
    }
    ElemType elem = _que.front();
    _que.pop();
    _notFull.notify();

    return elem;
}
}// end of namespace wd
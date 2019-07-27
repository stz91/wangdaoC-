#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

int ticketcount = 3;

class mutexLock
{
public:
    static mutexLock *getInstance()
    {
        if (_pInstance == nullptr)
        {
            _pInstance = new mutexLock();
        }
        return _pInstance;
    }
    static void destroy()
    {
        if (_pInstance)
        {
            delete _pInstance;
            _pInstance = nullptr;
        }
    }
    void lock()
    {
        while (mutex <= 0)
            ;
        --mutex;
    }
    void unlock()
    {
        if (mutex < 1)
            ++mutex;
    }

private:
    mutexLock()
        : mutex(1)
    {
    }
    ~mutexLock() {}
    static mutexLock *_pInstance;
    int mutex;
};

mutexLock *mutexLock::_pInstance = nullptr;

class condition
{
public:
    static condition *getInstance()
    {
        if (_pInstance == nullptr)
        {
            _pInstance = new condition();
        }
        return _pInstance;
    }
    static void destroy()
    {
        if (_pInstance)
        {
            delete _pInstance;
            _pInstance = nullptr;
        }
    }
    void wait()
    {
        --mutex;
        int previousMutex = mutex; //实现先等待后唤醒, 防止竞争
        while (mutex <= previousMutex)
            ;
    }
    void notify()
    {
        ++mutex; //先等待的后唤醒
    }
    void notifyAll()
    {
        mutex = 0;
    }

private:
    condition() {}
    ~condition() {}
    static condition *_pInstance;
    int mutex = 0;
};

condition *condition::_pInstance = nullptr;

void *func1(void *p)
{
    mutexLock *p1 = mutexLock::getInstance();
    condition *p2 = condition::getInstance();
    while (1)
    {
        p1->lock();
        if (ticketcount > 0)
        {
            cout << "pthId1 sale begins, rest ticketcount = " << ticketcount << endl;
            sleep(1);
            ticketcount--;
            if (ticketcount == 0)
                p2->notify();
            cout << "pthId1 sale finished, rest ticketcount = " << ticketcount << endl;
        }
        else
        {
            p1->unlock();
            pthread_exit(nullptr);
        }
        p1->unlock();
        sleep(1);
    }
}
void *func2(void *p)
{
    mutexLock *p1 = mutexLock::getInstance();
    condition *p2 = condition::getInstance();
    while (1)
    {
        p1->lock();
        if (ticketcount > 0)
        {
            cout << "pthId2 sale begins, rest ticketcount = " << ticketcount << endl;
            sleep(1);
            ticketcount--;
            if (ticketcount == 0)
                p2->notify();
            cout << "pthId2 sale finished, rest ticketcount = " << ticketcount << endl;
        }
        else
        {
            p1->unlock();
            pthread_exit(nullptr);
        }
        p1->unlock();
        sleep(1);
    }
}

void *func3(void *p)
{
    mutexLock *p1 = mutexLock::getInstance();
    condition *p2 = condition::getInstance();
    p1->lock();
    if (ticketcount > 0)
    {
        p1->unlock();
        p2->wait();
        p1->lock();
    }
    ticketcount = 3;
    p1->unlock();
    sleep(1);
    pthread_exit(nullptr);
}

int main()
{
    pthread_t pthId1 = 0;
    pthread_t pthId2 = 0;
    pthread_t pthId3 = 0;
    pthread_create(&pthId1, NULL, func1, NULL);
    pthread_create(&pthId2, NULL, func2, NULL);
    pthread_create(&pthId3, nullptr, func3, nullptr);
    pthread_join(pthId1, NULL);
    pthread_join(pthId2, NULL);
    pthread_join(pthId3, nullptr);
    mutexLock::destroy();
    condition::destroy();
    return 0;
}
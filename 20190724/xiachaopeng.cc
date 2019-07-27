#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

int ticketcount = 20;

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
        cout << "mutex = " << mutex << endl;
        while (mutex <= 0)
            ;
        --mutex;
    }
    void unlock()
    {
        cout << "mutex = " << mutex << endl;
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
        int previousMutex = mutex;
        while (mutex <= previousMutex && mutex < 0)
            ;
    }
    void notify()
    {
        ++mutex;
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
    while(ticketcount > 0)
    {
        cout << "pthId1 sale begins, rest ticketcount = " << ticketcount << endl;
        sleep(1);
        ticketcount--;
        cout << "pthId1 sale finished, rest ticketcount = " << ticketcount << endl;
    }
}

void *func2(void *p)
{
    while(ticketcount > 0)
    {
        cout << "pthId1 sale begins, rest ticketcount = " << ticketcount << endl;
        sleep(1);
        ticketcount--;
        cout << "pthId2 sale finished, rest ticketcount = " << ticketcount << endl;
    }
    
}

int main()
{
    pthread_t pthId1 = 0;
    pthread_t pthId2 = 0;
    pthread_create(&pthId1, NULL, func1, NULL);
    pthread_create(&pthId2, NULL, func2, NULL);
    pthread_join(pthId1,NULL);
    pthread_join(pthId2,NULL);
#if 0
    p->unlock();
    p2->unlock();
#endif

#if 0
    condition *p4=condition::getInstance();
    condition *p5=condition::getInstance();
    condition *p6=condition::getInstance();

    cout<<"p4="<<p4<<endl
        <<"p5="<<p5<<endl
        <<"p6="<<p6<<endl;

    p4->wait();
    cout<<"hello,world"<<endl;

    mutexLock::destroy();
    condition::destroy();
#endif

    return 0;
}
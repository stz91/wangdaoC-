#include "TaskQueue.h"
#include "Consumer.h"
#include "Producer.h"

#include "iostream"
#include <memory>
using namespace std;
using namespace wd;

int main(void)
{
    TaskQueue taskQue(20);

    unique_ptr<Thread> producer(new Producer(taskQue));
    unique_ptr<Thread> producer1(new Producer(taskQue));
    unique_ptr<Thread> consumer(new Consumer(taskQue));

    producer->start();
    producer1->start();
    consumer->start();

    producer->join();
    producer1->join();
    consumer->join();
    return 0;
}
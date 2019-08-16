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

    unique_ptr<Thread> producer(new Thread(std::bind(&Producer::fun, Producer(taskQue))));
    unique_ptr<Thread> consumer(new Thread(std::bind(&Consumer::fun, Consumer(taskQue))));

    producer->start();
    consumer->start();

    producer->join();
    consumer->join();
    return 0;
}
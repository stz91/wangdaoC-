#include "Thread.h"
#include <iostream>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory>

using namespace std;
using namespace wd;

class Mythread
: public Thread
{
public:
    void fun() override
    {
        ::srand(::clock());
        while(1)
        {
            int number = rand() % 100;
            cout << ">> number = " << number << endl;
            sleep(1);
        }
    } 
};

int main(void)
{
    Mythread thread1;
    // Mythread thread2(thread1);
    // Mythread thread2 = thread1;
    unique_ptr<Thread> thread(new Mythread());
    thread->start();
    thread->join();
    return 0;
}
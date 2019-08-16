#include "Thread.h"
#include <iostream>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory>

using namespace std;
using namespace wd;

class Task
{
public:
    void run()
    {
        ::srand(::clock());
        while (1)
        {
            int number = rand() % 100;
            cout << ">> number = " << number << endl;
            sleep(1);
        }
    }
};

void process()
{

    ::srand(::clock());
    while (1)
    {
        int number = rand() % 100;
        cout << ">> number = " << number << endl;
        sleep(1);
    }
}
int main(void)
{
    Task task;
    unique_ptr<Thread> thread(new Thread(std::bind(&Task::run, task)));
    // unique_ptr<Thread> thread(new Thread(process));
    // unique_ptr<Thread> thread(new Thread(std::bind(&Task::run, Task())));
    // bind()调用可以用对象，亦可以用对象引用
    thread->start();
    thread->join();
    return 0;
}
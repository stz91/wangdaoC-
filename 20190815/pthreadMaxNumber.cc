#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void *foo(void *arg)
{}

int main()
{
    int i = 0;
    pthread_t pthid;
    while(1)
    {
        if(pthread_create(&pthid, NULL, foo, NULL) != 0)
            break;
        ++i;
    }
    printf("%d\n", i);
    return 0;
     
}


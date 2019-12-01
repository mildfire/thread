#include <iostream>
#include <pthread.h>

void *thread_func(void *arg)
{
    char *msg = "thread_func1";
    return msg;
}

int main()
{
    pthread_t tid1, tid2;

    if(pthread_create(&tid1, NULL, thread_func, NULL) !=0)
    {


    }

    std::cout << "Hello World!" << std::endl;
    return 0;
}

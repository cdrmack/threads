#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *foo(void *)
{
    while (true)
    {
        puts("foo");
        sleep(1);
    }

    return NULL;
}

void bar()
{
    while (true)
    {
        puts("bar");
        sleep(2);
    }
}

int main()
{
    pthread_t foo_thread;
    pthread_create(&foo_thread, NULL, foo, NULL);

    bar();

    return EXIT_SUCCESS;
}

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *foo(void *)
{
    for (size_t i = 0; i < 8; ++i)
    {
        sleep(1);
        printf("[foo] %zu/8\n", i + 1);
    }

    return NULL;
}

void bar()
{
    for (size_t i = 0; i < 2; ++i)
    {
        sleep(2);
        printf("[bar] %zu/2\n", i + 1);
    }
}

int main()
{
    pthread_t foo_thread;
    pthread_create(&foo_thread, NULL, foo, NULL);

    bar();

    pthread_join(foo_thread, NULL);

    return EXIT_SUCCESS;
}

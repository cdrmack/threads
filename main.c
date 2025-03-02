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

void *add_magic(void *arg)
{
    int *base = (int *)arg;
    int *result = (int *)malloc(sizeof(int));

    printf("[add] arg = %d\n", *base);

    *result = *base + 42;
    printf("[add] result = %d\n", *result);
    return result;
}

int main()
{
    /* pthread_t foo_thread; */
    /* pthread_create(&foo_thread, NULL, foo, NULL); */

    /* bar(); */

    /* pthread_join(foo_thread, NULL); */

    int in = 8;
    pthread_t add_thread;
    pthread_create(&add_thread, NULL, add_magic, &in);

    int *out;
    pthread_join(add_thread, (void *)&out);

    printf("[main] result = %d\n", *out);

    return EXIT_SUCCESS;
}

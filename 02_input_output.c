#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
    int in = 8;
    pthread_t add_thread;
    pthread_create(&add_thread, NULL, add_magic, &in);

    int *out;
    pthread_join(add_thread, (void *)&out);

    printf("[main] result = %d\n", *out);

    return EXIT_SUCCESS;
}

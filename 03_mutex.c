/*
Threads should be used carefully.
In this example using threads is slower than running `count` twice in a row.
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define BIG_NUMBER 1000000UL
uint32_t counter = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *count(void *arg)
{
    for (size_t i = 0; i < BIG_NUMBER; ++i)
    {
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }

    return NULL;
}

int main()
{
    pthread_t count_thread;
    pthread_create(&count_thread, NULL, count, NULL);

    count(NULL);

    pthread_join(count_thread, NULL);

    printf("[main] result = %d\n", counter);

    return EXIT_SUCCESS;
}

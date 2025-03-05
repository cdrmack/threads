#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SEM_PRODUCER "/producer"
#define SEM_CONSUMER "/consumer"

sem_t *sem_prod;
sem_t *sem_cons;

int shared_number = 0;

void *producer(void *arg)
{
    for (size_t i = 0; i < 3; ++i)
    {
        puts("[producer] waiting for consumer to consume");
        sem_wait(sem_cons);
        puts("[producer] producing...");
        shared_number = i + 42;
        puts("[producer] produced, ready to be consumed");
        sem_post(sem_prod);
    }
    return NULL;
}

void *consumer(void *arg)
{
    for (size_t i = 0; i < 3; ++i)
    {
        puts("[consumer] waiting for producer to produce");
        sem_wait(sem_prod); // wait for producer to produce sth
        printf("[consumer] consumed shared_number = %d\n", shared_number);
        puts("[consumer] consumed, ready for sth new");
        sem_post(sem_cons); // consumer is ready for new thing
    }

    return NULL;
}

int main()
{
    sem_unlink(SEM_PRODUCER);
    sem_unlink(SEM_CONSUMER);

    sem_prod = sem_open(SEM_PRODUCER, O_CREAT, 0660, 0);
    sem_cons = sem_open(SEM_CONSUMER, O_CREAT, 0660, 1);

    pthread_t producer_thread;
    pthread_create(&producer_thread, NULL, producer, NULL);

    consumer(NULL);

    pthread_join(producer_thread, NULL);

    sem_close(sem_prod);
    sem_close(sem_cons);

    return EXIT_SUCCESS;
}

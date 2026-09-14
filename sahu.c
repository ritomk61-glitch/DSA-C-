#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5

sem_t chopstick[N];

void *philosopher(void *arg)
{
    int i = *(int *)arg;

    printf("Philosopher %d is thinking\n", i);
    sleep(1);

    sem_wait(&chopstick[i]);
    sem_wait(&chopstick[(i + 1) % N]);

    printf("Philosopher %d is eating\n", i);
    sleep(2);

    sem_post(&chopstick[i]);
    sem_post(&chopstick[(i + 1) % N]);

    printf("Philosopher %d finished eating\n", i);

    return NULL;
}

int main()
{
    pthread_t thread[N];
    int id[N];

    for (int i = 0; i < N; i++)
    {
        sem_init(&chopstick[i], 0, 1);
    }

    for (int i = 0; i < N; i++)
    {
        id[i] = i;
        pthread_create(&thread[i], NULL, philosopher, &id[i]);
    }

    for (int i = 0; i < N; i++)
    {
        pthread_join(thread[i], NULL);
    }

    for (int i = 0; i < N; i++)
    {
        sem_destroy(&chopstick[i]);
    }

    return 0;
}
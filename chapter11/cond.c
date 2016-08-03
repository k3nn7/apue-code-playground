#include <stdio.h>
#include <pthread.h>

pthread_cond_t ready;
pthread_mutex_t lock;

void *threadFunction(void *arg)
{
    printf("Second thread is waiting...\n");
    pthread_mutex_lock(&lock);
    pthread_cond_wait(&ready, &lock);
    pthread_mutex_unlock(&lock);
    printf("Thread finished.\n");
    pthread_exit((void*)0);
}

int main(int argc, char **argv)
{
    int err;
    pthread_t thread1, thread2;

    err = pthread_mutex_init(&lock, NULL);
    if (err != 0) {
        printf("Error while initializing mutex: %d\n", err);
        return 1;
    }

    err = pthread_cond_init(&ready, NULL);
    if (err != 0) {
        printf("Error while initializing conditional variable: %d\n", err);
        return 1;
    }

    err = pthread_create(&thread1, NULL, threadFunction, NULL);
    if (err != 0) {
        printf("Error while creating thread: %d\n", err);
        return 1;
    }

    err = pthread_create(&thread2, NULL, threadFunction, NULL);
    if (err != 0) {
        printf("Error while creating thread: %d\n", err);
        return 1;
    }

    printf("Press enter to continue...\n");
    getchar();

    pthread_mutex_lock(&lock);
    pthread_mutex_unlock(&lock);

    pthread_cond_broadcast(&ready);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_cond_destroy(&ready);
    pthread_mutex_destroy(&lock);

    return 0;
}
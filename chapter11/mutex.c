#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

struct data
{
    int count;
    int id;
    pthread_mutex_t lock;
};

struct data *d;

struct data *allocData(int id)
{
    struct data *d;
    int err;

    d = malloc(sizeof(struct data));
    if (d == NULL) {
        return d;
    }

    d->id = id;
    d->count = 0;

    err = pthread_mutex_init(&d->lock, NULL);
    if (err != 0) {
        free(d);
        return NULL;
    }
    return d;
}

void freeData(struct data *d)
{
    pthread_mutex_destroy(&d->lock);
    free(d);
}

void printData(struct data *d)
{
    printf("ID: %d, COUNT: %d\n", d->id, d->count);
}

void *notLockingThread(void *arg)
{
    for (int i = 0; i < 10000; i++) {
        d->count++;
    }
    pthread_exit((void *)0);
}

void *lockingThread(void *arg)
{
    for (int i = 0; i < 10000; i++) {
        pthread_mutex_lock(&d->lock);
        d->count++;
        pthread_mutex_unlock(&d->lock);
    }
    pthread_exit((void*)0);
}

void runForGivenThreadFunction(void * (*f)(void*))
{
    int err;
    pthread_t thread1, thread2;

    d = allocData(10);
    printData(d);

    err = pthread_create(&thread1, NULL, f, NULL);
    if (err != 0) {
        printf("Unable to create thread: %d\n", err);
        exit(1);
    }

    err = pthread_create(&thread2, NULL, f, NULL);
    if (err != 0) {
        printf("Unable to create thread: %d\n", err);
        exit(1);
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printData(d);

    freeData(d);
}

int main(int argc, char **argv)
{
    printf("Example with not locking thread:\n");
    runForGivenThreadFunction(notLockingThread);

    printf("Example with locking thread:\n");
    runForGivenThreadFunction(lockingThread);
    return 0;
}

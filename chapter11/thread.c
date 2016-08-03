#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_t thread;

void printPidTid()
{
    pid_t pid;
    pthread_t tid;

    pid = getpid();
    tid = pthread_self();

    printf("- PID: %lu\n- TID %u (0x%1x)\n",
           (unsigned long)pid,
           (unsigned int)tid,
           (unsigned int)tid);
}

void *threadFunction(void *arg)
{
    sleep(1);
    printf("Secondary thread:\n");
    printPidTid();

    pthread_exit((void *)123);
}

int main(int argc, char **argv)
{
    int err;
    void *threadReturn;

    err = pthread_create(&thread, NULL, threadFunction, NULL);
    if (err != 0) {
        printf("Cannot create thread: %d\n", err);
        return 1;
    }

    printf("Main thread:\n");
    printPidTid();

    printf("Joining with second thread...\n");
    err = pthread_join(thread, &threadReturn);
    if (err != 0) {
        printf("Cannot join with second thread: %d\n", err);
        return 1;
    }

    return 0;
}
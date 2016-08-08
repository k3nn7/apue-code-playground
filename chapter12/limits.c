#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <errno.h>

void printLimit(char *name, int id)
{
    long value;

    printf("Value for: %s ", name);

    errno = 0;
    value = sysconf(id);
    if (value < 0) {
        if (errno != 0) {
            if (errno == EINVAL)
                printf("(not supported)");
            else
                printf("(sysconf error");
        } else {
            printf("(no limit)");
        }
    } else {
        printf("%ld", value);
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    printLimit("PTHREAD_DESTRUCTOR_ITERATION", PTHREAD_DESTRUCTOR_ITERATIONS);
    printLimit("PTHREAD_KEYS_MAX", PTHREAD_KEYS_MAX);
    printLimit("PTHREAD_STACK_MIN", PTHREAD_STACK_MIN);
    return 0;
}
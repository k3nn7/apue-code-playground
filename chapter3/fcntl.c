#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdbool.h>

void printFlag(const char *name, bool on)
{
    if (on) {
        printf("* %s - ON\n", name);
    } else {
        printf("* %s - OFF\n", name);
    }
}

int main(int argc, char ** argv)
{
    int fd;
    int result;
    int accessFlags;

    if (argc != 2) {
        printf("Usage: ./a.out <descriptor number>\n");
        return 1;
    }

    fd = atoi(argv[1]);

    printf("File descriptor flags:\n");
    result = fcntl(fd, F_GETFD);

    printFlag("FD_CLOEXEC", result & FD_CLOEXEC);

    printf("File status access flags:\n");
    result = fcntl(fd, F_GETFL);
    accessFlags = result & O_ACCMODE;

    printFlag("O_RDONLY", accessFlags == O_RDONLY);
    printFlag("O_WRONLY", accessFlags == O_WRONLY);
    printFlag("O_RDWR", accessFlags == O_RDWR);

    printf("File status flags:\n");
    printFlag("O_APPEND", result & O_APPEND);
    printFlag("O_NONBLOCK", result & O_NONBLOCK);
    printFlag("O_SYNC", result & O_SYNC);
    printFlag("O_DSYNC", result & O_DSYNC);
    printFlag("O_FSYNC", result & O_FSYNC);
    printFlag("O_ASYNC", result & O_ASYNC);

    return 0;
}
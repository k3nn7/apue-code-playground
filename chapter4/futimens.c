#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main(int argc, char ** argv)
{
    int fd;
    struct stat statbuf;
    struct timespec times[2];


    if (argc != 2) {
        printf("Usage: ./a.out <path>");
        return 1;
    }

    if (stat(argv[1], &statbuf) < 0) {
        printf("stat error: %s\n", strerror(errno));
        return 1;
    }

    if ((fd = open(argv[1], O_RDWR | O_TRUNC)) < 0) {
        printf("open error: %s\n", strerror(errno));
        return 1;
    }

    times[0] = statbuf.st_atim;
    times[1] = statbuf.st_mtim;

    if (futimens(fd, times) < 0) {
        printf("futimens error: %s\n", strerror(errno));
        return 1;
    }

    return 0;
}
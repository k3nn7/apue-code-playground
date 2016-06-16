#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char ** argv)
{
    struct stat statbuf;

    if (argc != 2) {
        printf("Usage: ./a.out <path>\n");
        return 1;
    }

    if (stat(argv[1], &statbuf) < 0) {
        printf("stat error: %s\n", strerror(errno));
        return 1;
    }

    if (chmod(argv[1], statbuf.st_mode | S_ISGID) < 0) {
        printf("chmod error: %s\n", strerror(errno));
        return 1;
    }

    return 0;
}
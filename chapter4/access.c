#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>

bool isRealUserReadable(char * path)
{
    return faccessat(AT_FDCWD, path, R_OK, 0) == 0;
}

bool isRealUserWritable(char * path)
{
    return faccessat(AT_FDCWD, path, W_OK, 0) == 0;
}

bool isRealUserExecutable(char * path)
{
    return faccessat(AT_FDCWD, path, X_OK, 0) == 0;
}

bool isEffectiveUserReadable(char * path)
{
    return faccessat(AT_FDCWD, path, R_OK, AT_EACCESS) == 0;
}

bool isEffectiveUserWritable(char * path)
{
    return faccessat(AT_FDCWD, path, W_OK, AT_EACCESS) == 0;
}

bool isEffectiveUserExecutable(char * path)
{
    return faccessat(AT_FDCWD, path, X_OK, AT_EACCESS) == 0;
}

int main(int argc, char ** argv)
{
    int result;

    if (argc != 2) {
        printf("Usage: ./a.out <path>\n");
        return 1;
    }

    result = faccessat(AT_FDCWD, argv[1], F_OK, 0);
    if (result == -1) {
        printf("File %s error: %s\n", argv[1], strerror(errno));
        return 1;
    }

    printf("File %s:\n", argv[1]);

    if (isRealUserReadable(argv[1])) {
        printf("+ Readable for real user id\n");
    } else {
        printf("- Readable for real user id\n");
    }

    if (isRealUserWritable(argv[1])) {
        printf("+ Writable for real user id\n");
    } else {
        printf("- Writable for real user id\n");
    }

    if (isRealUserExecutable(argv[1])) {
        printf("+ Executable for real user id\n");
    } else {
        printf("- Executable for real user id\n");
    }

    if (isEffectiveUserReadable(argv[1])) {
        printf("+ Readable for effective user id\n");
    } else {
        printf("- Readable for effective user id\n");
    }

    if (isEffectiveUserWritable(argv[1])) {
        printf("+ Writable for effective user id\n");
    } else {
        printf("- Writable for effective user id\n");
    }

    if (isEffectiveUserExecutable(argv[1])) {
        printf("+ Executable for effective user id\n");
    } else {
        printf("- Executable for effective user id\n");
    }

    return 0;
}
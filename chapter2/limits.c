#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <errno.h>

void handleSysconfError()
{
    if (errno != 0) {
        if (errno == EINVAL) {
            printf(" (not supported)\n");
        } else {
            printf(" (sysconf error)\n");
        }
    } else {
        printf(" (no limit)\n");
    }
}

void printSysconf(const char * prefix, int name)
{
    long value;
    errno = 0;

    fputs(prefix, stdout);

    value = sysconf(name);
    if (value < 0) {
        handleSysconfError();
        return;
    }

    printf(" in sysconf = %ld\n", value);

}

void handlePathconfError()
{
    if (errno != 0) {
        if (errno == EINVAL) {
            printf("(not supported)\n");
        } else {
            printf("(pathconf error)\n");
        }
    } else {
        printf("(no limit)\n");
    }
}

void printPathconf(const char * prefix, char * path, int name)
{
    long value;
    errno = 0;

    printf("%s for path '%s' = ", prefix, path);

    value = pathconf(path, name);
    if (value < 0) {
        handlePathconfError();
        return;
    }

    printf("%ld\n", path, value);
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage: a.out <dirname>\n");
        return 1;
    }

    printf("ARG_MAX defined to be %ld\n", (long)ARG_MAX);
    printSysconf("ARG_MAX", _SC_ARG_MAX);

    printf("MAX_CANON defined to be %ld\n", (long)MAX_CANON);
    printPathconf("MAX_CANON", argv[1], _PC_MAX_CANON);

    printf("LINK_MAX defined to be %ld\n", (long)LINK_MAX);
    printPathconf("LINK_MAX", argv[1], _PC_LINK_MAX);

    return 0;
}

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int argc, char ** argv)
{
    int result;

    if (argc != 3) {
        printf("Usage: ./a.out <src_path> <dest_path>\n");
        return 1;
    }

    result = link(argv[1], argv[2]);
    if (result != 0) {
        printf("Link error: %s\n", strerror(errno));
        return 1;
    }

    return 0;
}

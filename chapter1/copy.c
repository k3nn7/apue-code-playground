#include <unistd.h>
#include <stdio.h>

#define BUFFSIZE 4096

int main(void)
{
    int r, w;
    char buf[BUFFSIZE];

    while ((r = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
        w = write(STDOUT_FILENO, buf, r);
        if (w != r) {
            printf("Write error\n");
            return 1;
        }
    }

    if (r < 0) {
        printf("Read error\n");
        return 1;
    }

    return 0;
}
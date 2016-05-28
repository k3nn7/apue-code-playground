#include <stdio.h>

int main(void)
{
    int c;

    while ((c = getc(stdin)) != EOF) {
        if (putc(c, stdout) == EOF) {
            printf("Error while writing to stdout\n");
            return 1;
        }
    }

    if (ferror(stdin)) {
        printf("Error while reading from stdin\n");
        return 1;
    }

    return 0;
}
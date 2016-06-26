#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char ** argv)
{
    FILE *f;
    int x, y;

    if (argc != 2) {
        printf("Usage: ./a.out <path>\n");
        return 1;
    }

    f = fopen(argv[1], "a");
    if (f == NULL) {
        printf("fopen error: %s\n", strerror(errno));
        return 1;
    }

    fprintf(f, "Typed coordinates:");

    printf("Type two, comma-separated coordinates (e.g. 123,123): ");

    scanf("%d,%d", &x, &y);

    fprintf(f, "X: %d Y: %d\n", x, y);

    fclose(f);
}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char ** argv)
{
    int size, newSize;
    int * values;

    printf("Type array size to create: ");
    if (scanf("%d", &size) != 1) {
        printf("Invalid value provided\n");
        return 1;
    }

    values = malloc(size * sizeof(int));
    if (values == NULL) {
        printf("malloc error: %s\n", strerror(errno));
        return 1;
    }

    for (int i = 0; i < size; i++) {
       values[i] = i * 5;
    }

    for (int i = 0; i < size; i++) {
        printf("Array element %d = %d\n", i, values[i]);
    }

    printf("Type new array size: ");
    if (scanf("%d", &newSize) != 1) {
        printf("Invalid value provided\n");
        return 1;
    }

    values = realloc(values, newSize);
    if (values == NULL) {
        printf("realloc error: %s\n", strerror(errno));
        return 1;
    }

    for (int i = 0; i < newSize; i++) {
        printf("Array element %d = %d\n", i, values[i]);
    }

    free(values);
    return 0;
}
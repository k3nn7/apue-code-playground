#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv)
{
    int fd;
    int offset;
    int bytesWritten;
    char *path = argv[1];

    char str1[] = "abcdefghij";
    char str2[] = "ABCDEFGHIJ";

    // Validate input arguments
    if (argc != 2) {
        printf("Usage: ./a.out <filename>\n");
        return 1;
    }

    // Open output file
    printf("Opening file %s\n", argv[1]);
    fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0755);

    if (fd < 0) {
        printf("Error while opening file %s: %s\n", path, strerror(errno));
        return 1;
    }

    // Get current file offset
    offset = lseek(fd, 0, SEEK_CUR);
    if (offset == -1) {
        printf("lseek error: %s\n", strerror(errno));
        return 1;
    }
    printf("Current offset in file: %d\n", offset);

    // Write 10 bytes
    bytesWritten = write(fd, str1, 10);
    if (bytesWritten != 10) {
        printf("Error while writting to file: %s\n", strerror(errno));
        return 1;
    }
    printf("%d bytes written\n", bytesWritten);

    // Get current file offset
    offset = lseek(fd, 0, SEEK_CUR);
    if (offset == -1) {
        printf("lseek error: %s\n", strerror(errno));
        return 1;
    }
    printf("Offset after writing '%s' is: %d\n", str1, offset);

    // Jump 22 bytes forward
    offset = lseek(fd, 22, SEEK_CUR);
    if (offset == -1) {
        printf("lseek error: %s\n", strerror(errno));
        return 1;
    }
    printf("Offset after jumping 22 bytes forward is: %d\n", offset);

    // Write 10 bytes
    bytesWritten = write(fd, str2, 10);
    if (bytesWritten != 10) {
        printf("Error while writting to file: %s\n", strerror(errno));
        return 1;
    }
    printf("%d bytes written\n", bytesWritten);

    // Get current file offset
    offset = lseek(fd, 0, SEEK_CUR);
    if (offset == -1) {
        printf("lseek error: %s\n", strerror(errno));
        return 1;
    }
    printf("Offset after writing '%s' is: %d\n", str2, offset);

    close(fd);

    return 0;
}
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char ** argv)
{
    int fd;
    int offset;
    int bytesWritten;

    // Validate input arguments
    if (argc != 2) {
        printf("Usage: ./a.out <path>\n");
        return 1;
    }

    // Open output file
    fd = open(argv[1], O_WRONLY | O_CREAT, 0755);
    if (fd < 0) {
        printf("Error while opening file %s: %s\n", argv[1], strerror(errno));
        return 1;
    }

    // Get current offset
    offset = lseek(fd, 0, SEEK_CUR);
    if (offset == -1) {
        printf("lseek error: %s\n", strerror(errno));
        return 1;
    }
    printf("Current offset in file: %d\n", offset);

    // Write 8 bytes at beginning of the file
    bytesWritten = write(fd, "|FOOBAR|", 8);
    if (bytesWritten != 8) {
        printf("write error: %s\n", strerror(errno));
        return 1;
    }

    // Get current offset
    offset = lseek(fd, 0, SEEK_CUR);
    if (offset == -1) {
        printf("lseek error: %s\n", strerror(errno));
        return 1;
    }
    printf("Offset after writing 8 bytes: %d\n", offset);

    // Rewind offset to beginning
    offset = lseek(fd, 0, SEEK_SET);
    if (offset == -1) {
        printf("lseek error: %s\n", strerror(errno));
        return 1;
    }
    printf("Offset after rewinding to file start: %d\n", offset);

    // Write 5 bytes with given offset
    bytesWritten = pwrite(fd, "|BAZ|", 5, 10);
    if (bytesWritten != 5) {
        printf("write error: %s\n", strerror(errno));
        return 1;
    }

    // Get current offset
    offset = lseek(fd, 0, SEEK_CUR);
    if (offset == -1) {
        printf("lseek error: %s\n", strerror(errno));
        return 1;
    }
    printf("Offset after writing 5 bytes with offset: %d\n", offset);

    close(fd);
    return 0;
}
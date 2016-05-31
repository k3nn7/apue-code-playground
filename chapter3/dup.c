#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

bool printOffset(int fd, int fd2)
{
    off_t offset;

    // Get current offset for fd
    offset = lseek(fd, 0, SEEK_CUR);
    if (offset == -1) {
        printf("lseek error: %s\n", strerror(errno));
        return false;
    }
    printf("Current offset for fd: %ld\n", (long)offset);

    // Get current offset for fd2
    offset = lseek(fd, 0, SEEK_CUR);
    if (offset == -1) {
        printf("lseek error: %s\n", strerror(errno));
        return false;
    }
    printf("Current offset for fd2: %ld\n", (long)offset);
    return true;
}

int main(int argc, char ** argv)
{
    int fd;
    int fd2;
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

    // Duplicate descriptor
    fd2 = dup(fd);
    if (fd2 < 0) {
        printf("Erro while duplicating descriptor: %s\n", strerror(errno));
        return 1;
    }

    // Print current offset
    if (!printOffset(fd, fd2)) {
        return 1;
    }

    // Write 8 bytes at beginning of the file using fd
    bytesWritten = write(fd, "|FOOBAR|", 8);
    if (bytesWritten != 8) {
        printf("write error: %s\n", strerror(errno));
        return 1;
    }
    printf("8 bytes written using fd\n");

    // Print current offset
    if (!printOffset(fd, fd2)) {
        return 1;
    }

    // Write 5 bytes using fd2
    bytesWritten = write(fd2, "|BAZ|", 5);
    if (bytesWritten != 5) {
        printf("write error: %s\n", strerror(errno));
        return 1;
    }
    printf("5 bytes written using fd2\n");

    // Print current offset
    if (!printOffset(fd, fd2)) {
        return 1;
    }

    close(fd2);
    close(fd);
    return 0;
}

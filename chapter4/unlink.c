#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main(int arvc, char ** argv)
{
    const char *tmpfile = "tmpfile";
    char buf[4];
    int fd;

    if ((fd = open(tmpfile, O_RDWR | O_CREAT, 0755)) < 0) {
        printf("open error: %s\n", strerror(errno));
        return 1;
    }

    printf("%s file opened successfully\n", tmpfile);

    if (unlink(tmpfile) < 0) {
        printf("unlink error: %s\n", strerror(errno));
        return 1;
    }

    printf("%s file unlinked\n", tmpfile);

    if (write(fd, "foo", 4) != 4) {
        printf("write error: %s\n", strerror(errno));
        return 1;
    }

    printf("foo written to %s file \n", tmpfile);

    lseek(fd, 0, SEEK_SET);

    if (read(fd, buf, 4) < 0) {
        printf("read error: %s\n", strerror(errno));
        return 1;
    }

    printf("Data read from file: %s\n", buf);

    return 0;
}
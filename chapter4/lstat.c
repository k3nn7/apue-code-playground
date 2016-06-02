#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

void printFileType(char * path)
{
    struct stat buf;
    char * typeStr;


    if(lstat(path, &buf) == -1) {
        printf("lstat error for file '%s': %s", path, strerror(errno));
        return;
    }

    if (S_ISREG(buf.st_mode))
        typeStr = "regular";
    if (S_ISDIR(buf.st_mode))
        typeStr = "directory";
    if (S_ISCHR(buf.st_mode))
        typeStr = "character device";
    if (S_ISBLK(buf.st_mode))
        typeStr = "block device";
    if (S_ISFIFO(buf.st_mode))
        typeStr = "fifo queue";
    if (S_ISLNK(buf.st_mode))
        typeStr = "symbolic link";
    if (S_ISSOCK(buf.st_mode))
        typeStr = "socket";

    printf("%s: %s\n", path, typeStr);
}

int main(int argc, char ** argv)
{
    for (int i = 0; i < argc; i++) {
        printFileType(argv[i]);
    }
    return 0;
}
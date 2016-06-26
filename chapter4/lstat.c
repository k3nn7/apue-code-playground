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

    printf("File %s:\n", path);
    printf("- Type: %s\n", typeStr);
    printf("- Size: %ld\n", buf.st_size);
    printf("- Last access time: %ld s %ld ns\n", buf.st_atim.tv_sec, buf.st_atim.tv_nsec);
    printf("- Last modification time: %ld s %ld ns\n", buf.st_mtim.tv_sec, buf.st_mtim.tv_nsec);
}

int main(int argc, char ** argv)
{
    for (int i = 1; i < argc; i++) {
        printFileType(argv[i]);
    }
    return 0;
}
#include <stdio.h>
#include <dirent.h>
#include <jmorecfg.h>
#include <errno.h>

boolean validateArguments(int argc)
{
    if (argc != 2) {
        printf("Usage: ls directory\n");
        return FALSE;
    }
    return TRUE;
}

boolean printDirectoryItems(char *path)
{
    DIR *dp;
    struct dirent *dirp;

    dp = opendir(path);
    if (dp == NULL) {
        char msg[80];
        sprintf(msg, "Can't open directory '%s'", path);
        perror(msg);
        return FALSE;
    }

    while ((dirp = readdir(dp)) != NULL) {
        printf("%s\n", dirp->d_name);
    }

    closedir(dp);
    return TRUE;
}

int main(int argc, char *argv[])
{
    if (!validateArguments(argc))
        return 1;

    if (!printDirectoryItems(argv[1]))
        return 1;

  return 0;
}


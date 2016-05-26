#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
  DIR *dp;
  struct dirent *dirp;

  if (argc != 2) {
    printf("Usage: ls directory\n");
    return 1;
  }

  dp = opendir(argv[1]);
  if (dp == NULL) {
    printf("Can't open directory %s\n", argv[1]);
    return 1;
  }

  while ((dirp = readdir(dp)) != NULL) {
    printf("%s\n", dirp->d_name);
  }

  closedir(dp);
  return 0;
}

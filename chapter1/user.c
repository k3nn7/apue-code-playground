#include <stdio.h>
#include <unistd.h>

int main(void)
{
    printf("Current user uid: %d gid: %d\n", getuid(), getgid());
    return 0;
}
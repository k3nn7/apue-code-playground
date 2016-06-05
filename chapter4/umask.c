#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define RWALL (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int main(int argc, char ** argv)
{
    creat("1foo", RWALL);
    umask(0);
    creat("2foo", RWALL);
    umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    creat("3foo", RWALL);
    return 0;
}
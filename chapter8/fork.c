#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char ** argv)
{
    pid_t pid;

    pid = fork();
    if (pid < 0) {
        printf("Fork error");
        return 1;
    } else if (pid == 0) {
        printf("I'm child, my pid is: %d\n", getpid());
    } else {
        printf("I'm parent, I spawned: %d. My pid is: %d\n", pid, getpid());
        printf("Waiting for child to terminate...\n");
        pid_t terminated = wait(NULL);
        printf("Child %d terminated\n", terminated);
    }

    printf("%d: terminates\n", getpid());
    return 0;
}
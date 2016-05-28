#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define MAXLINE 2048

int main()
{
    char buf[MAXLINE];
    pid_t pid;
    int status;

    printf("%% ");
    while (fgets(buf, MAXLINE, stdin) != NULL) {
        int lastChar = strlen(buf) - 1;
        if (buf[lastChar] == '\n')
            buf[lastChar] = 0;

        pid = fork();

        if (pid < 0) {
            printf("Fork error\n");
            return 1;
        }

        if (pid == 0) {
            execlp(buf, buf, (char*)0);
            printf("Error while executing %s\n", buf);
            return 1;
        }

        pid = waitpid(pid, &status, 0);
        if (pid < 0) {
            printf("waitpid error\n");
            return 1;
        }
        printf("%% ");
    }
    return 0;
}
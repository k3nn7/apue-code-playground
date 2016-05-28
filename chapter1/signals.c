#include <stdio.h>
#include <signal.h>

void handleSignal(int signo)
{
    printf("Got signal %d\n", signo);
}

int main(void)
{
    signal(SIGINT, handleSignal);

    char buf[255];
    while (fgets(buf, 255, stdin) != NULL) { }

    return 0;
}
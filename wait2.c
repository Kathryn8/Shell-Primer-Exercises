#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t child_pid;
    int status;
    int wait_return;
    child_pid = fork();
    if (child_pid == -1)
    {
        perror("Error:");
        return (1);
    }
    if (child_pid == 0)
    {
        printf("I am the child---Wait for me, wait for me\n");
        sleep(3);
        return (-1);
    }
    else
    {
        printf("I am the parent: child pid-%d\n", child_pid);
       wait_return = wait(&status);
        printf("the wait_return is %d\n", wait_return);
       printf("I am the father: %d---Oh, it’s all better now\n", status);
    }
    return (0);
}

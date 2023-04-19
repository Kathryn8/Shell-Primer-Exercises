#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t child_pid;
    int status;
    int wait_return;
    int i;

    i = 0;
    while (i < 5)
    {
	    child_pid = fork();
	    if (child_pid == -1)
	    {
		    perror("Error: fork failed");
		    return (1);
	    }
	    if (child_pid == 0)
	    {
		    printf("I am child number: %d\n", i);
		    printf("-------------------------------------\n");
		    sleep(3);
		    return (-1);
	    }
	    else
	    {
		    printf("This is iteration number %d\n", i);
		    printf("oooooooooooooooooooooooooooooooooooooooo\n");
		    wait_return = wait(&status);
		    printf("I am the parentand my child pid is %d\n", child_pid);
		    printf("the wait_return is %d\n", wait_return);
		    printf("I am the father: %d---Oh, it’s all better now\n", status);
	    }
	    i = i + 1;
    }
    return (0);
}

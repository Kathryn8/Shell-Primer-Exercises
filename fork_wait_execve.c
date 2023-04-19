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
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};
	
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
			printf("I am child process, iteration number: %d\n", i);
			printf("-------------------------------------\n");
			printf("Before execve...");
			sleep(1);
			printf("... waiting ...\n");
			sleep(2);
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
			}
			printf("After execve - ERROR\n");
			return (0);
		}
		else
		{
			wait_return = wait(&status);
			printf("oooooooooooooooooooooooooooooooooooooooo\n");
			printf("Waiting for  iteration %d to finish...\n", i);
		}
		i = i + 1;
	}
	printf("Program complete!\n");
	return (0);
}

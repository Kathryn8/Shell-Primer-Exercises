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
	//char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};
	char *argv[] = {"filename", NULL};
	size_t bytes;
	char *buffer;
	ssize_t got_line;

	bytes = 0;
	buffer = NULL;
	got_line = 0;
	while (1)
	{
		printf("$ ");
		got_line = getline(&buffer, &bytes, stdin);
		if (buffer == NULL)
		{
			printf("Error: getline failed\n");
			return (-1);
		}
		printf("Your command was: %s", buffer);
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error: fork failed");
			return (1);
		}
		if (child_pid == 0)
		{
			printf("I am child process, iteration number: %d\n", i);
			argv[0] = buffer;
			if (execve(buffer, argv, NULL) == -1)
			{
				perror("Error:");
			}
			printf("After execve - ERROR\n");
			return (0);
		}
		else
		{
			wait_return = wait(&status);
			printf("child process complete!\n");
		}
		printf("Program complete!\n");
		if (got_line == -1)
		{
			printf("exit\n");
			free(buffer);
			return (0);
		}
		free(buffer);
	}
	return (0);
}

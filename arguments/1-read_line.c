#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - a program that prints "$ ", wait for the user to enter a command, prints it on the next line.
 *
 * Return: always 0.
 */
int main()
{
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
		printf("%s", buffer);
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

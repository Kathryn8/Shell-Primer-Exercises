#include <stdio.h>
#include <unistd.h>

/**
 * main -  prints all the arguments, without using ac
 *
 * Return: number of arguments.
 */
int main(int ac, char **av)
{
	int i;

	i = 0;
	while (av[i] != NULL)
	{
		printf("%s\n", av[i]);
		i = i + 1;
	}
	return (i - 1);
}

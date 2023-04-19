#include <stdio.h>
#include <string.h>
#include <dirent.h>

int main (int argc, char *argv[], char *envp[])
{
	int i;
	char * string;
	char *delim;
	size_t n;
	char *env_key;
	DIR *directory_stream;
	int fd_dir;

	/*access and print from env, find PATH key:value pair*/
	env_key = "PATH";
	n = strlen(env_key);
	delim = ":";
	i = 0;
	while (envp[i] != NULL)
	{
		//printf("%s\n", envp[i]);
		if (strncmp(envp[i], env_key, n) == 0)
		{
			printf("found match: \n %s\n", envp[i]);
		}
		i = i + 1;
	}

	/*access and print from DIR, open and close DIR stream, set fd*/
	directory_stream = opendir("directory name");
	fd_dir = drfd(directory_stream);
	return (0);
}

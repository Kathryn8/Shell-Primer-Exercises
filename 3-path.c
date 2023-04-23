#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>

char *_strdup(char *str);
char *_strchr(char *s, char c);
void split_string_into_words(char* string, char** words);

int main (int argc, char *argv[], char *envp[])
{
	int i;
	char *string;
	char *paths;
	char *each_path[100];
	char *delim;
	size_t n;
	char *env_key;
	DIR *dp;
	struct dirent *ep;

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
			//printf("found match: \n %s\n", envp[i]);
			string = _strchr(envp[i], '=');
			paths = _strdup(string + 1);
			printf("%s\n", paths);
			split_string_into_words(paths, each_path);
		}
		i = i + 1;
	}
	/*iterate over each path from path variable: each_path: */
	i = 0;
	while (each_path[i] != NULL)
	{
		printf("PATH [%d]: %s\n", i , each_path[i]);
		i = i + 1;
	}
	return (0);
}

/**
 * _strchr -  locates a character in a string
 * @s: takes parameter pointer to a string
 * @c: a character
 *
 * Return: pointer to the character
 */

char *_strchr(char *s, char c)
{
	int i;
	char *ptr = NULL;

	i = 0;
	while (s[i] >= '\0')
	{
		if (s[i] == c)
		{
			ptr = &s[i];
			break;
		}
		i = i + 1;
	}
	return (ptr);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory, which
 *  contains a copy of the string given as a parameter
 * @str: string to be duplicated
 *
 * Return: a pointer to the duplicated string. It returns NULL if insufficient
 *  memory was available
 */

char *_strdup(char *str)
{
	char *new_str;
	int i;
	int j;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
		i = i + 1;
	new_str = (char *)malloc(i + 1);
	if (new_str == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		new_str[j] = str[j];
		j = j + 1;
	}
	return (new_str);
}

void split_string_into_words(char* string, char** words)
{
	char* word = strtok(string, ":");
	int i = 0;

	while (word != NULL)
	{
		words[i] = word;
		i = i + 1;
		word = strtok(NULL, ":");
	}
	words[i] = NULL;
}

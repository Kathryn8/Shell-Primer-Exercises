#include <stdio.h>
#include <string.h>

void split_string_into_words(char* string, char** words) {
	char* word = strtok(string, " ");
	int i = 0;
	while (word != NULL) {
		words[i] = word;
		i++;
		word = strtok(NULL, " ");
	}
}

int main() {
	char my_string[] = "Hello world, how are you?";
	char* words[100];
	int i;

	split_string_into_words(my_string, words);
	i = 0;
	while (words[i] != NULL)
	{
		printf("%s\n", words[i]);
		i = i + 1;
	}
	return 0;
}

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main (void)
{
	DIR *dp;
	struct dirent *ep;

	dp = opendir ("./");
	if (dp == NULL)
	{
		perror ("Couldn't open the directory");
	}
	ep = readdir(dp);
	if (ep == NULL)
	{
		printf("Error: Could not read directory\n");
	}
	while (ep != NULL)
	{
		printf("%s\t%ld\t%ld\t%d\t%c\n", ep->d_name, ep->d_ino, ep->d_off, ep->d_reclen, ep->d_type);
		ep = readdir(dp);
	}
	(void) closedir (dp);
	return 0;
}

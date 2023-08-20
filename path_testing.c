#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char *_getpath(char *str);
int main(void)
{
	char *pa;

	pa = _getpath("PATH");
	printf("%s", pa);
	return (0);
}

char *_getpath(char *str)
{
	int a = 0;
	char *tkn, *encpy;
	extern char **environ;

	while(environ[a])
	{
		encpy = strdup(environ[a]);
		tkn = strtok(encpy, "=");
		if (strcmp(tkn, str) == 0)
			return (strtok(NULL, "="));
		free(encpy);
		a++;
	}
	return (NULL);
}

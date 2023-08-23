#include "main.h"
/**
 * free_token_array - Its free memory adresses
 * @tokens: list of array to free
 *
 * Return: no return value;
 */
void free_token_array(char **tokens)
{
	int i = 0;

	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}
/**
 * _getpath - get the environment PATH value
 * @str: path variable to get
 *
 * Return: return the path value
 */
char *_getpath(char *str)
{
	int a = 0;
	char *tk, *encpy, *rst = NULL;

	while (environ[a])
	{
		encpy = strdup(environ[a]);
		tk = strtok(encpy, "=");
		if (strcmp(tk, str) == 0)
			rst = strdup(strtok(NULL, "="));
		free(encpy);
		a++;
	}
	return (rst);
}
/**
 * comment_handler - handle the comment pass to args
 * @str: string of argument
 * Return: No return value
 */
void comment_handler(char **str)
{
	int i = 0;

	if ((*str)[i] == '#')
	{
		while ((*str)[i])
		{
			if ((*str)[i] != '#')
				break;

			(*str)++;
		}
	}
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strcmp - Write a function that compares two strings.
 *
 * @s1: This is the input string
 * @s2: This is the input string
 *
 * Return: If the strings are equals return "0", if not return other number
 */

int _strcmp(char *s1, char *s2)
{
	for (; (*s1 != '\0' && *s2 != '\0') && (*s1 == *s2); s1++, s2++)
		;
	if (*s1 == *s2)
	{
		return (0);
	}
	return (*s1 - *s2);
}

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
		if (_strcmp(tk, str) == 0)
			rst = strdup(strtok(NULL, "="));
		free(encpy);
		a++;
	}
	return (rst);
}

/**
 * comment_handler - handle the comment pass to args
 * @source: string of argument
 * Return: No return value
 */
void comment_handler(char *source)
{
	int i = 0;

	while (source[i] != '\0')
	{
		if (i > 0 && source[i] == '#' && source[i - 1] != ' ')
			break;
		if (source[i] == '#')
		{
			source[i] = '\0';
			break;
		}
		i++;
	}
}

/**
 * word_len - function to count number of letters of
 * each word
 * @str: word
 * Return: number of letters of tje word
**/
int word_len(char *str)
{
	int index = 0, len = 0;

	while (*(str + index) && *(str + index) != ' ')
	{
		len++;
		index++;
	}
	return (len);
}

/**
 * count_words - functin to count number of words
 * @str: string
 * Return: number of words
**/
int count_words(char *str)
{
	int index = 0, words = 0, len = 0;

	for (index = 0; *(str + index); index++)
		len++;
	for (index = 0; index < len; index++)
	{
		if (*(str + index) != ' ')
		{
			words++;
			index += word_len(str + index);
		}
	}
	return (words);
}

#include "main.h"
/**
 * proc_path - function to process execve path args
 * @tokens: tokenized array
 * @path: path
 * Return: return full path
**/
char  *proc_path(char **tokens, char *path)
{
	char *token = NULL, *combine = NULL, *temp = NULL;
	const char s[2] = ":";
	struct stat st;

	if (stat(tokens[0], &st) == 0)
	{
		/*
		*combine = malloc(sizeof(char) * _strlen(tokens[0])),
		*_strcpy(combine, tokens[0]),
		*free(path),
		*return (combine);
		*/
		free(path);
		return (tokens[0]);
	}
	else
	{
		temp = malloc(sizeof(char) * (_strlen(path) + 1));
		_strcpy(temp, path);
		token = strtok(temp, s);
		while (token != NULL)
		{
			combine = malloc(sizeof(char) * (_strlen(token) + _strlen(tokens[0]) + 2));
			_strcpy(combine, token);
			_strcat(combine, "/");
			_strcat(combine, tokens[0]);
			if (stat(combine, &st) == 0)
			{
				free(temp), free(path);
				return (combine);
			}
			free(combine);
			token = strtok(NULL, s);
		}
		free(temp);
	}
	return (NULL);
}

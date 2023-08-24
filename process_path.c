#include "main.h"
/**
 * proc_path - function to process execve path args
 * @tokens: tokenized array
 * @path: path
 * Return: return full path
**/
<<<<<<< HEAD
char *proc_path(char **tokens, char *path)
=======
char  *proc_path(char **tokens, char *path)
>>>>>>> 26804c8959950ad8a947fbe6b3509cf67f87e496
{
	char *token = NULL, *combine = NULL, *temp = NULL;
	const char s[2] = ":";
	struct stat st;

	if (stat(tokens[0], &st) == 0)
	{
<<<<<<< HEAD
		combine = malloc(sizeof(char *) * _strlen(tokens[0]) + 1);
		_strcpy(combine, tokens[0]);
		free(path);
		return (combine);
	}
	else
	{
		temp = malloc(sizeof(char *) * (_strlen(path) + 1));
		if (temp == NULL)
			return (NULL);
=======
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
>>>>>>> 26804c8959950ad8a947fbe6b3509cf67f87e496
		_strcpy(temp, path);
		token = strtok(temp, s);
		while (token != NULL)
		{
			combine = malloc(sizeof(char) * (_strlen(token) + _strlen(tokens[0]) + 2));
<<<<<<< HEAD
			if (combine == NULL)
				return (NULL);
=======
>>>>>>> 26804c8959950ad8a947fbe6b3509cf67f87e496
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
<<<<<<< HEAD
		free(temp), free(path);
=======
		free(temp);
>>>>>>> 26804c8959950ad8a947fbe6b3509cf67f87e496
	}
	return (NULL);
}

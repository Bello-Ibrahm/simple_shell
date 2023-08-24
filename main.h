#ifndef MAIN_H
#define MAIN_H
#define UNUSED(x) (void)(x)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdbool.h>


/**
 * struct builtin - data structure for builtin command
 * @name: name of the builtin command
 * @func: builtin command function
 *
 * Description: builtin command  structure
 */
typedef struct builtin
{
	char *name;
	void (*func)(char **args);
} builtin;

extern int errno;
extern char **environ;

char *_getline(void);
char **_token(char *line_arg);
void signal_handler(int x);
void signal_handler2(int x);
void exec_cmd(char **tokens, char **argv, char *line, char **env);
void _error(char *msg, char **argv);
char *_getpath(char *str);
char  *proc_path(char **tokens, char *path);
void exec_builtin(char **tokens, char *line);
void comment_handler(char *source);
int count_words(char *str);
void free_token_array(char **token);
void _env(char **args);


char *_strcpy(char *dest, char *src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
int _putchar(char c);
void _puts(char *str);
int _atoi(char *s);
char *_strstr(char *haystack, char *needle);
#endif

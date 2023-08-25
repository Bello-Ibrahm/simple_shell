#ifndef MAIN_H
#define MAIN_H
#define UNUSED(x) (void)(x)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <ctype.h>

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
	void (*func)(char **args, char **argv);
} builtin;

extern int errno;
extern char **environ;


char *str_sanitizer(char *source);
char *_getline(void);
char **_token(char *line_arg);
void signal_handler(int x);
void signal_handler2(int x);
void exec_cmd(char **tokens, char **argv, char *line, char **env);
void _error(char *msg, char **argv);
void err_msg(int fd, int num_cmd, char *s1, char *s2, char *s3);
char *_getpath(char *str);
char  *proc_path(char **tokens, char *path);
void exec_builtin(char **tokens, char **argv, char *line);
void comment_handler(char *source);
int count_words(char *str);
void free_token_array(char **token);
void _env(char **args, char **argv);

char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
int _putchar(char c);
void _puts(char *str);
int _atoi(char *s);
char *_strstr(char *haystack, char *needle);
#endif

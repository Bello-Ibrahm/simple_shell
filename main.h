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

char *_getline(void);
char **_token(char *line_arg);
void signal_handler(int x);
int  exec_cmd(char **args, char **argv, char **env);
void _error(char *msg, char **argv);
char *_path(char *cmd, char **env);

int count_words(char *str);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
void free_token_array(char **token);
char *_strcat(char *dest, char *src);
void comment_handler(char **str);
#endif

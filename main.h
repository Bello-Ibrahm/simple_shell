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
void exec_cmd(char **arg, char **argv);
void _error(char *msg, char **argv);

#endif

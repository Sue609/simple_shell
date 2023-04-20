#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

extern char **environ;


void tokenizer(char *comand, char *delimiter);
void print_env();
void get_command(char **comand, size_t *n);
void prompt(void);

#endif

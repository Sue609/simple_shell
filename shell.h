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

void run_cd_command(char **token_arr, int token_index);
void run_exit_command();
void run_ls_command(char **token_arr, int status);
void run_env_command();
void tokenizer(char *comand, char *delimiter);
void print_env(void);
void get_command(char **comand, size_t *n);
void prompt(void);

#endif

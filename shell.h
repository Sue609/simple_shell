#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#define BUFFER_SIZE 1024

#define MAX_ALIAS_COUNT 100
#define MAX_ALIAS_NAME_LENGTH 50
#define MAX_ALIAS_VALUE_LENGTH 100

int _strlen(char *s);
char *_strcpy(char *dest, char *src);
void print_aliases(void);
void set_alias(char *name, char *value);
void handle_alias(char *input);

size_t my_strcspn(const char *s, const char *reject);
char* my_strchr(const char *s, int c);
size_t my_strspn(const char *str, const char *delimiters);

void execute_comand(char **token_arr, char *comand);
void tokenize_comand(char *comand, char *delimiter, char **token_arr, int *token_count);

void print_current_directory();
extern char **environ;
char* custom_strtok(char *str, const char *delimiters);
int my_strcmp(const char *s1, const char *s2);
void my_memcpy(char *dest, const char *src, size_t n);
int read_input(char *buffer);
char *get_line(char *buffer, int *position, int bytes_read, int *line_pos);
char *my_getline(char *buffer);
void run_cd_command(char **token_arr, int token_index);
void run_exit_command(char *str[], int index);
void run_ls_command(char **token_arr, int status);
void run_env_command();
void tokenizer(char *comand, char *delimiter);
void print_env(void);
void get_command(char **comand);
void prompt(void);

#endif

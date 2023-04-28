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

/**
 * struct alias_t - struct
 * @name: name
 * @value: value
 * Description: This struct is for alias
 */
struct alias_t
{
	char name[MAX_ALIAS_NAME_LENGTH];
	char value[MAX_ALIAS_VALUE_LENGTH];
};
int _strlen(char *s);
char *_strcpy(char *dest, char *src);

char *expand_line(char *line, int *line_pos, int size);

int my_atoi(char *str);
unsigned int my_strlen(const char *s);

void print_aliases(void);
void set_alias(char *name, char *value);
void handle_alias(char *input);

size_t my_strcspn(const char *s, const char *reject);
char *my_strchr(const char *s, int c);
size_t my_strspn(const char *str, const char *delimiters);

void execute_comand(char **token_arr, char *comand);
void tokenize_comand(char *comand, char *delimiter,
	char **token_arr, int *token_count);

void get_command(char **comand, size_t *n);
void print_current_directory(void);
extern char **environ;
char *custom_strtok(char *str, const char *delimiters);
int my_strcmp(const char *s1, const char *s2);
void my_memcpy(char *dest, const char *src, size_t n);
int read_input(char *buffer);
char *get_line(char *buffer, int *position, int bytes_read, int *line_pos);
char *my_getline(char *buffer);
void run_cd_command(char **token_arr, int token_index);
void run_exit_command(char *str[], int index);
void run_ls_command(char **token_arr, int status);
void run_env_command(void);
void tokenizer(char *comand, char *delimiter);
void print_env(void);
void prompt(void);

int is_builtin_comand(char *comand);
void handle_builtin_comands(char **token_arr, int token_index);
void handle_external_comands(char **token_arr, char **env);

int my_strncmp(const char *s1, const char *s2, size_t n);
char *my_getenv(const char *name);
size_t m_strlen(const char *str);
int my_setenv(char *name, char *value, int overwrite);
int my_unsetenv(char *name);

#endif

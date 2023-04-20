#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
extern char **environ;

/**
 * prompt - prompt a user to type command
 * Return: nothing
 */

void prompt(void)
{
        char create_prompt[] = "#buddies$ ";

        write(STDOUT_FILENO, create_prompt, strlen(create_prompt));
}

/**
 * get_command - gets user input
 * @comand: pointer to memory/buffer
 * @n: size of the buffer
 * Return: nothing
 */

void get_command(char **comand, size_t *n)
{
        ssize_t characters_read;

        characters_read = getline(comand, n, stdin);

        if (characters_read < 0)
        {
                printf("\n");
                free(comand);
                exit(0);
        }
        (*comand)[strcspn(*comand, "\n")] = '\0';
}
/**
 * tokenizer - tokenize a string
 * @comand: pointer to the string
 * @delimiter: pointer to the tokens
 * Return: nothing
 */

void print_env()
{
    char **env = environ;
    while (*env)
    {
        printf("%s\n", *env);
        env++;
    }
}

void tokenizer(char *comand, char *delimiter)
{
        char *token;
        int token_index = 0;
        char *token_arr[100];
        int status;
        pid_t child;
        char **env = environ;

        token = strtok(comand, delimiter);
        while (token != NULL)
        {
                token_arr[token_index] = token;
                token_index++;
                token = strtok(NULL, delimiter);
        }
        token_arr[token_index] = NULL;
        if (strcmp(token_arr[0], "cd") == 0)
{
    char *dir;
    if (token_index == 1) {
        dir = getenv("HOME");
    } else if (strcmp(token_arr[1], "-") == 0) {
        dir = getenv("OLDPWD");
    } else {
        dir = token_arr[1];
    }

    char *current_dir = getcwd(NULL, 0);  // get current directory
    if (current_dir == NULL) {
        perror("getcwd");
        exit(EXIT_FAILURE);
    }

    if (chdir(dir) == -1) {  // change directory
        perror("cd");
    } else {
        // update PWD environment variable
        if (setenv("OLDPWD", current_dir, 1) == -1) {
            perror("setenv");
        }
        char *new_dir = getcwd(NULL, 0);
        if (new_dir == NULL) {
            perror("getcwd");
            exit(EXIT_FAILURE);
        }
        if (setenv("PWD", new_dir, 1) == -1) {
            perror("setenv");
        }
        free(new_dir);
    }
    free(current_dir);
}

        else if (strcmp(token_arr[0], "exit") == 0)
        {
                exit(0);
        }
        else if (strcmp(token_arr[0], "ls") == 0)
        {
                child = fork();
                if (child == -1)
                {
                        perror("fork unsuccrsful");
                        exit(EXIT_FAILURE);
                }
                else if (child == 0)
                {
                        execvp(token_arr[0], token_arr);
                        perror("./shell");
                        exit(EXIT_FAILURE);
                } else
                {
                        waitpid(child, &status, 0);
                }
        }

        else if (strcmp(token_arr[0], "pwd") == 0)
           {
                char *current_dir = getcwd(NULL, 0);
                 if (current_dir == NULL)
                 {     
                         perror("getcwd");
                         exit(EXIT_FAILURE);
                 }
                 printf("%s\n", current_dir);
                 free(current_dir);
          }

        else if (strcmp(token_arr[0], "env") == 0)
        {
                print_env();
        }

        else
        {
                child = fork();
                if (child == -1)
                {
                        exit(EXIT_FAILURE);
                }
                else if (child == 0)
                {
                        execve(token_arr[0], token_arr, env);
                        perror("./shell");
                        exit(EXIT_FAILURE);
                }
                else
                {
                        waitpid(child, &status, 0);
                }
        }
}

/**
 * main - runs a simple unix command interpreter
 * Return: last command executed
 */
int main(void)
{
       char *comand = NULL;
        size_t n = 0;
        char delimiter[] = " \t\n";

        while (1)
        {
                comand = (char *)malloc(100 * sizeof(char));
                prompt();
                get_command(&comand, &n);
                tokenizer(comand, delimiter);
                free(comand);
       }
        return (0);
}



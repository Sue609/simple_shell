#include "shell.h"

/**
 * tokenizer - function that breaks down string commands.
 * @comand: string of commands to be broken down
 * @delimiter: characters to be used in breaking the string
 * Return: nothing
 */
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
		if (token_index == 1)
		{
			chdir(getenv("HOME"));
		}
		else
		{
			chdir(token_arr[1]);
		}
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
			perror("fork unsuccessful");
			exit(EXIT_FAILURE);
		}
		else if (child == 0)
		{
			execvp(token_arr[0], token_arr);
			perror("./shell");
			exit(EXIT_FAILURE);
		}
		else
		{
			waitpid(child, &status, 0);
		}
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
		} else
		{
			waitpid(child, &status, 0);
		}
	}
}

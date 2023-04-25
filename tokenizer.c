#include "shell.h"

/**
 * tokenizer - function that splits string of commands
 * @comand: string to break
 * @delimiter: character to use to break
 * Return: Nothing
 */
void tokenizer(char *comand, char *delimiter)
{
	char *token;
	int token_index = 0;
	char *token_arr[100];
	int status;
	char **env = environ;

	token = strtok(comand, delimiter);
	while (token != NULL)
	{
		if (token[0] != '#')
		{
			token_arr[token_index] = token;
			token_index++;
		}
		token = strtok(NULL, delimiter);
	} token_arr[token_index] = NULL;
	if (my_strcmp(token_arr[0], "cd") == 0)
		run_cd_command(token_arr, token_index);
	else if (my_strcmp(token_arr[0], "exit") == 0)
		run_exit_command();
	else if (my_strcmp(token_arr[0], "ls") == 0)
		run_ls_command(token_arr, status);
	else if (my_strcmp(token_arr[0], "env") == 0)
		run_env_command();
/*	else if (my_strcmp(token_arr[0], "alias") == 0)
		hendle_alias(comand);*/
	else
	{
		pid_t child = fork();

		if (child == -1)
			exit(EXIT_FAILURE);
		else if (child == 0)
		{
			execve(token_arr[0], token_arr, env);
			perror("./shell");
			exit(EXIT_FAILURE);
		} else
			waitpid(child, &status, 0);
	}
}

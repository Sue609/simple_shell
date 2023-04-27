#include "shell.h"


/**
 * tokenizer - function that splits string of commands
 * @comand: string to break
 * @delimiter: character to use to break
 * Return: Nothing
 */
void tokenizer(char *comand, char *delimiter)
{

	char *token_arr[100];
	char *token;
	int token_index = 0;

	if (comand == NULL)
		return;

	token = custom_strtok(comand, delimiter);
	while (token != NULL)
	{
		if (token[0] != '#')
		{
			token_arr[token_index] = token;
			token_index++;
		}
		else
		{
			break;
		}
		token = custom_strtok(NULL, delimiter);
	}
	token_arr[token_index] = NULL;

	execute_comand(token_arr, comand);
}

/**
 * execute_comand - function that executes a comand
 * @token_arr: the string passed as comands
 * @comand: The comands passed
 * Return:pointer
 */
void execute_comand(char **token_arr, char *comand)
{
	int token_index = 0;
	int status = 0;
	pid_t child;
	char **env = environ;

	if (token_arr == NULL || token_arr[0] == NULL)
		return;

	if (my_strcmp(token_arr[0], "cd") == 0)
		run_cd_command(token_arr, token_index);

	else if (my_strcmp(token_arr[0], "exit") == 0)
		run_exit_command(&token_arr[0], token_index);

	else if (my_strcmp(token_arr[0], "ls") == 0)
		run_ls_command(token_arr, status);

	else if (my_strcmp(token_arr[0], "env") == 0)
		run_env_command();

	/*else if (my_strcmp(token_arr[0], "alias") == 0)
		handle_alias(comand);*/

	else if (my_strcmp(token_arr[0], "pwd") == 0)
		print_current_directory();
	else
	{
		child = fork();
		if (child == -1)
			exit(EXIT_FAILURE);
		else if (child == 0)
		{
			execve(token_arr[0], token_arr, env);
			perror("./shell");
			exit(EXIT_FAILURE);
		}
		else
			waitpid(child, &status, 0);
	}
}

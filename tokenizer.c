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
			if (token_index > 0 && strcmp(token_arr[token_index - 1], ";") == 0)
			{
				token_arr[token_index - 1] = NULL;
				execute_comand(token_arr);
				token_index = 0;
			}
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

	execute_comand(token_arr);
}

/**
 * execute_comand - function that executes a comand
 * @token_arr: the string passed as comands
 * @comand: The comands passed
 * Return:pointer
 */
void execute_comand(char **token_arr)
{
	int token_index = 0, status = 0;
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
	else if (my_strcmp(token_arr[0], "unsetenv") == 0)
	{
		if (token_arr[1] != NULL)
			my_unsetenv(token_arr[1]);
		else
			perror("Error: unable to set env variables"); }
	else if (my_strcmp(token_arr[0], "env") == 0)
		run_env_command();
	else if (my_strcmp(token_arr[0], "setenv") == 0)
	{
		if (token_arr[1] != NULL && token_arr[2] != NULL)
			my_setenv(token_arr[1], token_arr[2], 1);
		else
			perror("Error: invalid arguments for setenv\n"); }
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
			exit(EXIT_FAILURE); }
		else
			waitpid(child, &status, 0); }
}

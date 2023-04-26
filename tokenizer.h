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
	int token_index = 0;
	char *token;
	char **env = environ;

	token = custom_strtok(comand, delimiter);
	while(token != NULL)
	{
		if (token[0] != '#')
		{
			token_arr[token_index] = token;
			token_index++;
		}
		token = custom_strtok(NULL, delimiter);
	}
	if (is_builtin_comand(token_arr[0]))
	{
		handle_builtin_comands(token_arr, token_index);
	}
	else
	{
		handle_external_comands(token_arr, env);
	}
}

int is_builtin_comand(char *comand)
{
	if (my_strcmp(comand, "cd") == 0 || my_strcmp(comand, "exit") == 0 )
		return (1);

	else if(my_strcmp(comand, "env") == 0 || my_strcmp(comand, "ls") == 0)
		return (1);

	else if (my_strcmp(comand, "pwd") == 0)
		return (1);
	else
		return (0);
}


/**
 * tokenize_comand - function that tokenizes a comand.
 * @comand: command to be executed.
 * @delimiter: position where string to be spilit.
 * @token_arr: character double pointer array.
 * @token_count: numer of tokens after tokenization.
 *
 * Return: nothing.
 */
void tokenize_comand(char *comand, char *delimiter,
		char **token_arr, int *token_count)
{
	char *token;

	token = custom_strtok(comand, delimiter);
	while (token != NULL)
	{
		if (token[0] != '#')
		{
			token_arr[*token_count] = token;
			(*token_count)++;
		}

		token = custom_strtok(NULL, delimiter);
		}
	token_arr[*token_count] = NULL;
}

/**
 * execute_comand - function that executes the tokenizer commands.
 * @token_arr: character double pointer array.
 * @comand: comand to be executed.
 *
 * Return: nothing.
 */
void handle_builtin_comands(char **token_arr, int token_index);
{
	if (my_strcmp(token_arr[0], "cd") == 0)
		run_cd_command(token_arr, token_index);

	else if (my_strcmp(token_arr[0], "exit") == 0)
		run_exit_command(&token_arr[0], token_index);

	else if (my_strcmp(token_arr[0], "ls") == 0)
		run_ls_command(token_arr, status);

	else if (my_strcmp(token_arr[0], "env") == 0)
		run_env_command();

	else if (my_strcmp(token_arr[0], "alias") == 0)
		handle_alias(comand);

	else if (my_strcmp(token_arr[0], "pwd") == 0)
		print_current_directory();
	
	
void handle_external_commands(char **token_arr, char **env)
{
	int status;
	pid_t child = fork();

	if (child == -1)
		exit(EXIT_FAILURE);
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

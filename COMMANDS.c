#include "shell.h"

/**
 * run_cd_command - function runs change directory command.
 * @token_arr: double character pointer.
 * @token_index: integer to the token index.
 *
 * Return: nothing.
 */

void run_cd_command(char **token_arr, int token_index)
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



/**
 * run_exit_command - function that exits a command.
 * @str: character pointer.
 * @index: integer index.
 *
 * Return: nothing
 */

void run_exit_command(char *str[], int index)
{
	int status;

	if (my_strcmp(str[0], "exit") == 0)
	{
		if (index == 1)
			exit(0);

		else if(index == 2 && my_strcmp(str[0], "exit") == 0)
		{
			status = atoi(str[1]);
			exit(status);
		}
	}
	
}



/**
 * run_ls_command - this function runs the list command.
 * @token_arr: double character pointer .
 * @status: status of PID.
 *
 * Return: nothing.
 */

void run_ls_command(char **token_arr, int status)
{
	pid_t child = fork();

	if (child == -1)
	{
		perror("Fork Unsuccessful");
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



/**
 * run_env_command - this function prints the env.
 *
 * Return: nothing.
 */

void run_env_command(void)
{
	print_env();
}

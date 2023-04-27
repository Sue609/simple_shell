#include "shell.h"
#include <errno.h>

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
		chdir(my_getenv("HOME"));
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

	if (index == 2 && my_strcmp(str[0], "exit") == 0)
	{
		status = my_atoi(str[1]);
		exit(status);
	}
	else if (index == 1 && my_strcmp(str[0], "exit") == 0)
	{
		exit(0);
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
		perror("fork unsuccrsful");
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

/**
 * print_current_directory - function that prints pwd.
 *
 * Retrun: noting.
 */
void print_current_directory(void)
{
	char *cwd;
	size_t dir_size = 1024;
	char *current_dir = (char *) malloc(dir_size);

	if (current_dir == NULL)
	{
		perror("Unable to allocate memory for directory");
		exit(EXIT_FAILURE);
	}
	cwd = getcwd(current_dir, dir_size);

	if (cwd == NULL)
	{
		perror("Error getting current directory");
		free(current_dir);
		exit(EXIT_FAILURE);
	}
	setenv("PWD", cwd, 1);
	write(STDOUT_FILENO, cwd, my_strlen(cwd));
	write(STDOUT_FILENO, "\n", 1);

	free(current_dir);
}

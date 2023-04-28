#include "shell.h"

/**
 * my_unsetenv - function that unsets the environment
 * @name: the string to be handled
 *
 * Return: 0 on sucess
 */
int my_unsetenv(char *name)
{
	int ret = unsetenv(name);

	if (ret == -1)
	{
		perror("Error: Could not unset environment\n");
		return(1);
	}
	return(0);
}

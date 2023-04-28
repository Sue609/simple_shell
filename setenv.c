#include "shell.h"

/**
 * my_setenv - function that sets the environment
 * @name: the string
 * @value: the string to be set
 * @overwrite: the environment
 * Return: an integer
 */
int my_setenv(char *name, char *value, int overwrite)
{
	int ret = setenv(name, value, overwrite);

	if (ret == -1)
	{
		perror("Error: Couldnot set environment variable\n");
	}
	return (0);
}

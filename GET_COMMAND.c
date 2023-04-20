#include "shell.h"


/**
 * get_comand - This function accepts a users input.
 * @comand: a pointer to char array which will store users input.
 * @n: pointer to store size of the input buffer.
 *
 * Return: nothing.
 */

void get_comand(char **comand, size_t *n)
{
	ssize_t characters_read;

	characters_read = getline(comand, n, stdin);

	if (characters_read < 0)
	{
		printf("\n");
		free(comand);
		exit(0);
	}

	(*comand)[strcspn(comand, "\n")] = '\0';  /* Removes new line characters*/

}

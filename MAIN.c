#include "shell.h"

/**
 * main - The beginning of the program.
 * @void the main function does not take any parameters.
 *
 * Return: 0 on success.
 */

int main(void)
{
	char delimeter[] = " \t\n";
	char *comand = NULL;
	size_t n = 0;

	while (1)
	{
		if (getline(&comand, &n, stdin) == -1)
			break;
		if (comand[strlen(comand) - 1] == '\n')
			comand[strlen(comand) - 1] = '\0';
		tokenizer(comand, delimeter);
	}
	return (0);
}

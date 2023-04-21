#include "shell.h"

/**
 * get_command - gets user input
 * @comand: pointer to memory/buffer
 * @n: size of the buffer
 * Return: nothing
 */
void get_command(char **comand, size_t *n)
{
	ssize_t characters_read;
	
	characters_read = getline(comand, n, stdin);

	if (characters_read < 0)
	{
		printf("\n");
		free(comand);
		exit(0);
	}
	(*comand)[strcspn(*comand, "\n")] = '\n';
}

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
		comand = (char *)malloc(100 * sizeof(char));
		prompt();
		get_command(&comand, &n);
		tokenizer(comand, delimeter);
		free(comand);
	}

	return (0);
}

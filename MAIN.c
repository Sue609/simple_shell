#include "shell.h"

/**
 * get_command - This function gets user input
 * @comand: pointer to a char array which stores users input.
 * @n: size_t.
 *
 * Return: nothing
 */
void get_command(char **comand, size_t *n)
{
	ssize_t characters_read;
	*comand = NULL;

	while (*comand == NULL || strlen(*comand) == 0)
	{
		prompt();
		characters_read = getline(comand, n, stdin);

		if (characters_read == -1)
		{
			exit(0);
		}
	}
	(*comand)[strcspn(*comand, "\n")] = '\0';
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
		get_command(&comand, &n);
		tokenizer(comand, delimeter);
		free(comand);
	}
	return (0);

}

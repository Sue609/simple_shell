#include "shell.h"

/**
 * get_command - This function gets user input
 * @comand: pointer to a char array which stores users input.
 *
 * Return: nothing
 */
void get_command(char **comand)
{
	*comand = my_getline(*comand);

	if (*comand == NULL)
	{
		printf("\n");
		exit(0);
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
	static char buffer[BUFFER_SIZE];

	while (1)
	{
		prompt();
		comand = my_getline(buffer);

		get_command(&comand);
		tokenizer(comand, delimeter);
		free(comand);
	}
	return (0);

}

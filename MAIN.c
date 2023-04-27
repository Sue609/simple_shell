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
	char *start;
	ssize_t characters_read;
	char *end;
	*comand = NULL;

	while (*comand == NULL || strlen(*comand) == 0)
	{
		characters_read = getline(comand, n, stdin);

		if (characters_read == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			exit(0);
		}

		if (characters_read == 1 && (*comand)[0] == '\n')
		{
			free(*comand);
			*comand = NULL;
			continue;
		}

		start = *comand;
		while (*start == ' ' || *start == '\t')
		{
			start++;
		}
		if (*start == '\n')
		{
			free(*comand);
			*comand = NULL;
			continue;
		}
		end = *comand + strlen(*comand) - 1;

		while (end > start && (*end == ' ' || *end == '\t' || *end == '\n'))
		{
			end--;
		}

		*(end + 1) = '\0';
	}
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
	
	comand = (char *)malloc(10 * sizeof(char));
	while (1)
	{
		get_command(&comand, &n);
		tokenizer(comand, delimeter);
		free(comand);
	}
	free(comand);
	return (0);

}

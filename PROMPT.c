#include "shell.h"


/**
 * prompt - it displays a prompt and waits for the user to type a command.
 *
 * Return: nothing.
 */

void prompt(void)
{
	char create_prompt[] = "#prompt$ ";

	write(STDOUT_FILENO, create_prompt, strlen(create_prompt));

}

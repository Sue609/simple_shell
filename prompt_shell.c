#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

extern chr **environ;

/**
 * get_line - function used read an entire line of text from a stream.
 * @line: character pointer variable to store the line.
 *
 * Return: nothing.
 */
void get_line(char **line)
{
	ssize_t char_read;
	size_t size = 0;

	char_read = getline(line, &size, stdin);

	if (char_read < 0)
	{
		printf("\n");
		exit(0);
	}

	(*line)[strcspn(*line, "\n")] = '\0';
}

/**
 * promp - variable that takes a prompt.
 *
 * Return: nothing.
 */

void prompt(void);
{
	char my_prompt[] = "#buddies$ ";
	write(STDOUT_FILENO, my_prompt, strlen(my_prompt));
}

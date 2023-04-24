#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

/**
 * my_memcpy - function that copies string
 * @src: variable having source string
 * @dest: variable having destination string
 * @n: variable to hold the count
 * Return: nothing
 */
void my_memcpy(char *dest, const char *src, size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
}

/**
 * read_input - function that read in the inputon commandline
 * @buffer: the  variable to hold the string passed
 * Return: integer
 */
int read_input(char *buffer)
{
	int bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);

	if (bytes_read < 0)
	{
		printf("Error reading input\n");
		exit(1);
	}
	return (bytes_read);
}

/**
 * get_line - function to get input from the user on command line
 * @buffer: variable holding the  inputs
 * @position: variable tracking the prompt or cursor
 * @bytes_read: varible holding the the read string
 * @line_pos: variable holding the position of the prompt's real time
 * Return: nothing
 */
char *get_line(char *buffer, int *position, int bytes_read, int *line_pos)
{
	char *line = malloc(BUFFER_SIZE);

	if (!line)
		perror("malloc");
		exit(EXIT_FAILURE);
	while (*position < bytes_read)
	{
		char c = buffer[(*position)++];

		if (c == '\n')
		{
			if (*line_pos % BUFFER_SIZE == 0)
			{
				char *new_line = malloc(*line_pos + 1 + BUFFER_SIZE);

				if (!new_line)
					perror("malloc");
					exit(EXIT_FAILURE);
				my_memcpy(new_line, line, *line_pos + 1);
				free(line);
				line = new_line;
			}
			linw[*line_pos] = '\0';
			return (line);
		}
		else
		{
			if (*line_pos % BUFFER_SIZE == 0)
				char *new_line = malloc(*line_pos + BUFFER_SIZE);

				if (!new_line)
					perror("malloc");
					exit(EXIT_FAILURE);
				my_memcpy(new_line, line, *line_pos);
				free(line);
				line = new_line;
			line[(*line_pos)++] = c;
		}
	}
	return (NULL);
}

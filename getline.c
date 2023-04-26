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
	size_t i;

	for (i = 0; i < n; i++)
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
		write(STDERR_FILENO, "Error reading input\n", 20);
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
	char c;

	if (!line)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	while (*position < bytes_read)
	{
		c = buffer[(*position)++];

		if (c == '\n')
		{
			line[*line_pos] = '\0';
			return (line);
		}

		else
		{
			line[(*line_pos)++] = c;

			if (*line_pos % BUFFER_SIZE == 0)
			{
				line = expand_line(line, line_pos, *line_pos + 1);
			}
		}
	}

	free(line);
	return (NULL);
}



/**
 * expand_line - function that increases size of line buffer.
 * @line: line to be expanded.
 * @line_pos: integer.
 * @size: size of the line to be expanded.
 *
 * Return: a character.
 */
char *expand_line(char *line, int *line_pos, int size)
{
	char *new_line;
	int new_size = size + BUFFER_SIZE;

	new_line = malloc(new_size);

	if (!new_line)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	my_memcpy(new_line, line, *line_pos);
	free(line);
	*line_pos = 0;

	return (new_line);
}

#include "shell.h"

/**
 * my_getline - function that takes a character pointer array.
 * @buffer: pointer to a buffer.
 *
 * Return: char pointer.
 */

char *my_getline(char *buffer)
{
	static int position;
	static int bytes_read;
	int line_pos = 0;

	if (position == 0 || position == bytes_read)
	{
		bytes_read = read_input(buffer);

		position = 0;
		if (bytes_read == 0)
		{
			return (NULL);
		}
	}

	return (get_line(buffer, &position, bytes_read, &line_pos));
}

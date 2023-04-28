#include "shell.h"
#include <ctype.h>

/**
 * is_number - function that looks for the number.
 * @s: character pointer string.
 *
 * Return: nothing.
 */

int is_number(char *s)
{
	int i = 0;

	if (s[i] == '-')
	{
		i++;
	}

	for (; s[i] != '\0'; i++)
	{
		if (!isdigit(s[i]))
		{
			return 0;
		}
	}
	return 1;
}

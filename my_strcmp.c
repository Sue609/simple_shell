#include "shell.h"

/**
 * my_strcmp - function that compares strings.
 * @s1: constant chracter pointer.
 * @s2: constant character pointer.
 *
 * Return: an inte value
 */

int my_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}

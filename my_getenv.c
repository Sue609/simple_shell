#include "shell.h"
/**
 * my_getenv - function that gets environment.
 * @name: constant character environ.
 *
 * Return: getenv.
 */

char *my_getenv(const char *name)
{
	char **env = environ;
	size_t namelen = m_strlen(name);

	for (; *env != NULL; env++)
	{
		if (my_strncmp(name, *env, namelen) == 0 && (*env)[namelen] == '=')
		{
			return (&((*env)[namelen + 1]));
		}
	}
	return (NULL);
}


/**
 * m_strlen - function that counts a string.
 * @str: te string to be calculated.
 *
 * Return: number of characters in a string.
 */
size_t m_strlen(const char *str)
{
	size_t len = 0;

	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}


/**
 * my_strncmp - function thet compares two strings.
 * @s1: string to compare with.
 * @s2: string to be compared with.
 *
 * @n: number of bytes to compare.
 * Return: an intager.
 */
int my_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && *s2 && n--)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	if (n == 0)
		return (0);
	else
		return (*s1 - *s2);
}

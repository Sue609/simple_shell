#include "shell.h"

/**
 * my_atoi - converts the string to an integer and return results.
 * @str: a string representation.
 *
 * Return: an int.
 */
int my_atoi(char *str)
{
	int result = 0;
	int i;
	int digit;

	for (i = 0; str[i] != '\0' && (str[i]) >= '0' && str[i] <= '9'; i++)
	{
		digit = str[i] - '\0';
		result = result * 10 + digit;
	}

	return (result);
}

/**
 * my_strlen - function that calculates length of a string.
 * @s: the string to be calculated.
 *
 * Return: length of the string.
 */
unsigned int my_strlen(const char *s)
{
	unsigned int len = 0;

	while (*s++ != '\0')
		len++;

	return (len);
}

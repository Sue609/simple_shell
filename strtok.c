#include "shell.h"

/**
 * custom_strtok - function to tokenize a string.
 * @str: a function to input string.
 * @delimeters: pointer to string of delimeter characters.
 *
 * Return: a character pointer.
 */

char *custom_strtok(char *str, const char *delimeters)
{
	static char *next_token;
	char *token;

	if (str != NULL)
	{
		next_token = str;
	}

	token = next_token;
	if (token == NULL)
	{
		return (NULL);
	}

	token += my_strspn(token, delimeters);

	if (*token == '\0')
	{
		next_token = NULL;
		return (NULL);
	}

	next_token = token + my_strcspn(token, delimeters);

	if (*next_token != '\0')
	{
		*next_token = '\0';
		next_token++;
	}

	return (token);
}

/**
 * my_strcspn - calculates length of initial segment os string s.
 * @s: pointer to string to be searched.
 * @reject: pointer to string to be rejected.
 *
 * Return: an integer.
 */
size_t my_strcspn(const char *s, const char *reject)
{
	size_t n = 0;

	while (*s)
	{
		if (my_strchr(reject, *s))
			return (n);

		else
			s++, n++;
	}

	return (n);
}


/**
 * my_strchr - function that searches for the first occurence of 'c'.
 * @s: a constant characer.
 * @c: an integer.
 *
 * Return: pointer to first occurence of c.
 */

char *my_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);

		s++;
	}

	if (c == '\0')
		return ((char *)s);

	return (NULL);
}


/**
 * my_strspn - loops over string until it finds a char that is not delimeters.
 * @str: constant character string.
 * @delimiters: the specified delimeter.
 *
 * Return: length of enntire string.
 */
size_t my_strspn(const char *str, const char *delimiters)
{
	size_t i = 0;
	int j;

	while (str[i] != '\0')
	{
		j = 0;
		while (delimiters[j] != '\0')
		{
			if (str[i] == delimiters[j])
			{
				break;
			}
			j++;
		}
		if (delimiters[j] == '\0')
		{
			break;
		}
		i++;
	}

	return (i);
}

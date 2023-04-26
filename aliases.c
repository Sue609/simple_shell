#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * print_aliases - function that prints existing aliases
 * Return: Nothing
 */
void print_aliases(void)
{
	int alias_count = 0;
	int i;
	alias_t aliases[MAX_ALIAS_COUNT];

	for (i = 0; i < alias_count; i++)
	{
		printf("%s = '%s'\n", aliases[i].name, aliases[i].value);
	}
}

/**
 * set_alias - function that create or modify an alias
 * @name: name of the alias
 * @value: the string which is the value
 * Return: nothing
 */
void set_alias(char *name, char *value)
{
	int alias_count = 0;
	int i;
	alias_t aliases[MAX_ALIAS_COUNT];

	if (alias_count >= MAX_ALIAS_COUNT)
	{
		printf("Error: Too many aliases\n");
		return;
	}
	for (i = 0; i < alias_count; i++)
	{
		if (strcmp(aliases[i].name, name) == 0)
		{
			_strcpy(aliases[i].value, value);
			return;
		}
	}
	_strcpy(aliases[alias_count].name, name);
	_strcpy(aliases[alias_count].value, value);
	alias_count++;
}

/**
 * handle_alias - handles the alias command
 * @input: the string the user inputs
 * Return: nothing
 */
void handle_alias(char *input)
{
	char *token;
	int i;
	int alias_count = 0;
	char name[MAX_ALIAS_NAME_LENGTH];
	char value[MAX_ALIAS_VALUE_LENGTH];
	alias_t aliases[MAX_ALIAS_COUNT];

	if (_strlen(input) == 5)
	{
		print_aliases();
		return;
	}
	token = strtok(input + 6, "=");
	_strcpy(name, token);

	token = strtok(NULL, "=");

	if (token == NULL)
	{
		for (i = 0; i < alias_count; i++)
		{
			if (strcmp(aliases[i].name, name) == 0)
			{
				printf("%s = '%s'\n", aliases[i].name, aliases[i].value);
			}
		}
	}
	else
	{
		_strcpy(value, token);
		set_alias(name, value);
	}
}

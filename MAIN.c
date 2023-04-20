/**
 * main - The beginning of the program.
 * void@ the main function does not take any parameters.
 *
 * Return: 0 on success.
 */

int main(void)
{
	char delimeter[] = " \t\n";
	char *comand = NULL;
	size_t n = 0;

	while (1)
	{
		comand = (char *)malloc(100 * sizeof(char));
		prompt();
		get_command(&comand, &n);
		tokenizer(comand, delimeter);
		free(comand);
	}

	return (0);
}

/**
 * main - The beginning of the program.
 * void@ the main function does not take any parameters.
 *
 * Return: 0 on success.
 */

int main(void)
{
	char delimeter[] = " \t\n";
	char *command = NULL;
	size_t n = 0;

	while (1)
	{
		command = (char *)malloc(100 * sizeof(char));
		prompt();
		get_command(&command, &n);
		tokenizer(command, delimeter);
		free(command);
	}

	return (0);
}

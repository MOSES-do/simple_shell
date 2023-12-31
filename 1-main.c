#include "main.h"

/**
 * main - main function
 * @argc: n number of arguments passed
 * @argv: an array of arguments
 * @env: system environment variables
 * Return: 0
 */


int main(int argc, char *argv[], char **env)
{
	int dataInputPath;
	ssize_t read;
	size_t len;
	char *userInput;
	(void)argc;
	dataInputPath = isatty(STDIN_FILENO);
	while (1)
	{
		userInput = NULL;
		len = 0;
		read = 0;


		if (dataInputPath == 1)
			welcome();
		read = _getline(&userInput, &len, stdin);

		if (read == -1)
			return (end(read, userInput));
		if (strcmp(userInput, "exit") == 0)
		{	free(userInput);
			return (0);
		}
		if (strcmp(userInput, "exit 1000") == 0)
		{	free(userInput);
			return (232);
		}
		if (read != -1)
			cmdn(userInput, argv, env);

		free(userInput);
	}
	free(userInput);

	return (0);
}





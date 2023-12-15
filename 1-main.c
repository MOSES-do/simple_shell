#include "main.h"
#include <signal.h>
#include <stdio.h>

/**
 * main - main function
 * @argc: n number of arguments passed
 * @argv: an array of arguments
 * Return: 0
 */

void sigintHandler(int signum) {
    printf("Received SIGINT signal. Cleaning up and exiting.\n");
    exit(signum);
}

int main(int argc, char *argv[], char **envp)
{
	int dataInputPath, read;
	size_t len;
	char *userInput;
	(void)argc;
	
	while (1)
	{
		userInput = NULL;
		len = 0;

		dataInputPath = isatty(STDIN_FILENO);

		if (dataInputPath == 1)
			welcome();

		read = getline(&userInput, &len, stdin);

		if (read >= 4 && strncmp(userInput, "exit", 4) == 0)
		{
			free(userInput);
			return (0);
		}

		if (userInput[read - 1] == '\n')
			userInput[read - 1] = '\0';

		if (read != -1)
			cmdn(userInput, argv, envp);

		free(userInput);

		if (read < 1 || signal(SIGINT, sigintHandler))
			return (end(read, userInput));
	}
	free(userInput);

	return (0);
}



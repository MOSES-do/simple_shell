#include "main.h"

/**
 * execFilePath - executes file path
 * @argv: arguments
 * Return: 0
 */


int execFilePath(char *argv[], char *progname[], char **envp)
{
	pid_t pid;

	pid = fork();

	if (pid == 0)
	{
		if(execve(argv[0], argv, envp) == -1)
		{
			perror(progname[0]);
			free(argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	wait(NULL);
	free(argv[0]);
	return (0);
}



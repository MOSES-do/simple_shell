#include "main.h"

/**
 * execFilePath - executes file path
 * @argv: arguments
 * Return: 0
 */


int execFilePath(char *argv[], char *progname[])
{
	pid_t pid;

	pid = fork();

	if (pid == 0)
	{
		if(execve(argv[0], argv, NULL) == -1)
		{
			perror(progname[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(NULL);

	return (0);
}



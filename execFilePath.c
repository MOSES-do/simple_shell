#include "main.h"

/**
 * execFilePath - executes file path
 * @argv: arguments
 * Return: 0
 */


int execFilePath(char *argv[])
{
	pid_t pid;

	pid = fork();

	if (pid == 0)
	{
		execve(argv[0], argv, NULL);
	}
	else
		wait(NULL);

	return (0);
}



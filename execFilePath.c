#include "main.h"

/**
 * execFilePath - executes file path
 * @argv: arguments
 * @progname: name of the programs .exe
 * @envp: system environment variables
 * Return: 0
 */


int execFilePath(char *argv[], char *progname[], char **envp)
{
	pid_t pid;

	pid = fork();

	if (pid == 0)
	{
		if (execve(argv[0], argv, envp) == -1)
		{
			perror(progname[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(NULL);



	return (0);
}




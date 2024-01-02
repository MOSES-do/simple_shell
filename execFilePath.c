#include "main.h"
/**
 * execFilePath - executes file path
 * @argv: arguments
 * @progname: name of the programs .exe
 * @envp: system environment variables
 * @file: newly generated path from environment variable
 * Return: 0
 */


int execFilePath(char *argv[], char *progname[], char **envp, char *file)
{
	pid_t pid;

	pid = fork();

	(void)progname;
	if (pid == 0)
	{
		if (access(argv[0], F_OK) == 0)
			execve(argv[0], argv, envp);
		else
			execve(file, argv, envp);
	}
	else
		wait(NULL);

	return (0);
}





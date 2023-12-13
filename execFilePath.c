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
		if (argv[1])
		{
			write(STDOUT_FILENO, "./shell", 7);
			write(STDOUT_FILENO, ": No such file or directory", 27);
			putchar('\n');
		}
		else
		{
			if (argv[0])
			{
				if (execve(argv[0], argv, NULL) == -1)
				{
					perror("./shell");
					return (-1);
				}
			}
			else
			{
				write(STDOUT_FILENO, "./shell", 5);
				write(STDOUT_FILENO, ": No such file or directory", 27);
				putchar('\n');
			}
		}
	}
	else
		wait(NULL);
	return (0);
}

/**
 * AnotherexecFilePath - executes file path
 * @argv: parameter
 * Return: 0
 */

int AnotherexecFilePath(char *argv[])
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("./shell");
			return (-1);
		}
	}
	else
		wait(NULL);

	return (0);
}


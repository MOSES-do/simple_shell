#include "main.h"
/**
 * checkPath - check if path exists
 * @argv: user generated tokens
 * @progname: exe. program name
 * Return: 0
 */
int checkPath(char *argv[], char *progname[])
{
	if (access(argv[0], F_OK) == 0)
		execFilePath(argv);
	else
		perror(progname[0]);
	return (0);
}

/**
 * cmdn - performs strtok function
 * @buffer: parameter
 * @pgname: exe. program name
 * Return: 0
 */
int cmdn(char *buffer, char *pgname[])
{
	char *token, *tokens[64];
	int count = 0, i = 0;

	token = strtok(buffer, " ");
	while (token != NULL && count < 64)
	{
		tokens[count] = strdup(token);
		token = strtok(NULL, " ");
		count++;
	}
	tokens[count] = NULL;
	checkPath(tokens, pgname);

	for (i = 0; i < count; i++)
		free(tokens[i]);
	return (0);
}

/**
 * welcome - performs the write function
 * Return: 0
 */
int welcome(void)
{
	printstdout("#cisfun ");
	fflush(stdout);
	return (0);
}

/**
 * end - exit the shell on call
 * @read: if value == -1, exit shell
 * Return: reutnrs 0 on success
 */
int end(int read)
{
	if (read == -1)
	{
		return (0);
	}
	return (0);
}


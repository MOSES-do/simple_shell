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
	write(STDOUT_FILENO, "#cisfun ", 8);
	return (0);
}

/**
 * my_getchar - returns read function
 * Return: &status
 */

int my_getchar(void)
{
	char status;

	return ((read(0, &status, 1) == 1) ? (unsigned char)status : EOF);
}

/**
 * customGetchar - modifies getline to read multiline characters
 * Return: returns read characters
 */
int customGetchar(void)
{
	int ch = my_getchar();

	if (!(ch == EOF || ch == '\n'))
		_putchar(ch);

	return (ch);
}




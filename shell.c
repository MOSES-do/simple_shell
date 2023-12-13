#include "main.h"

/**
 * cmdn - performs strtok function
 * @buffer: parameter
 * Return: 0
 */

int cmdn(char *buffer)
{
	char *token, *tokens[32];
	int count = 0, i = 0;

	token = strtok(buffer, " ");
	while (token != NULL && count < 32)
	{
		tokens[count] = strdup(token);
		token = strtok(NULL, " ");
		count++;
	}
	tokens[count] = NULL;
	execFilePath(tokens);

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
 * Anothercmdn - strok function
 * @buffer: parameter
 * Return: 0
 */

int Anothercmdn(char *buffer)
{
	char *token, *tokens[32];
	int count = 0, i = 0;

	token = strtok(buffer, " ");
	while (token != NULL && count < 32)
	{
		tokens[count] = strdup(token);
		token = strtok(NULL, " ");
		count++;
	}
	tokens[count] = NULL;
	AnotherexecFilePath(tokens);

	for (i = 0; i < count; i++)
		free(tokens[i]);

	return (0);
}

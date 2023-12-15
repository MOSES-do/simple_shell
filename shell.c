#include "main.h"
/**
 * checkPath - check if path exists
 * @argv: user generated tokens
 * @progname: exe. program name
 * Return: 0
 */

 /*
int checkPath(char *argv[], char *progname[], char **env)
{
	if (access(argv[0], F_OK) == 0)
		execFilePath(argv, progname, env);
	else
		write(STDOUT_FILENO, progname[0], strlen(progname[0]));
	return (0);
}
*/
/**
 * cmdn - performs strtok function
 * @buffer: parameter
 * @pgname: exe. program name
 * Return: 0
 */
int cmdn(char *buffer, char *pgname[], char **envp)
{
	char **bufcpy, *token, *cpybuf;
	int k, b = 0, j = 0, count = 0;
	(void)pgname;
	(void)envp;
	
	cpybuf = malloc(sizeof(char) * strlen(buffer)+ 1);
	if (cpybuf == NULL)
		return (0);
	strcpy(cpybuf, buffer);
	token = strtok(buffer, " ");
	while (token != NULL)
	{
		token = strtok(NULL, " ");
		count++;
	}
	
	bufcpy = malloc(sizeof(char*) * count + 1);
	if (bufcpy == NULL)
		return (0);
	token = strtok(cpybuf, " ");
	
	for(b = 0; token != NULL; b++)
	{
		bufcpy[b] = malloc(sizeof(char) * strlen(token)+ 1);
		if (bufcpy[b] == NULL)
		{
			free(buffer);
			free(cpybuf);
			for (k = j; k >= 0; k--)
				free(bufcpy[k]);
			free(bufcpy);
			perror("Error");
			return (0);
		}
		strcpy(bufcpy[b], token);
		token = strtok(NULL, " ");
	}
	bufcpy[b] = NULL;
	free(cpybuf);
	/*checkPath(tokens, pgname, envp);*/
	execFilePath(bufcpy, pgname, envp);
	free(bufcpy);
	/*for (i = 0; i < count; i++)
		free(tokens[i]);*/
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
int end(int read, char *freeUserInput)
{
	(void)freeUserInput;
	if (read == -1)
	{
		/*free(freeUserInput);*/
		return (0);
	}
	return (0);
}


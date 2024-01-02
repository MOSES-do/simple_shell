#include "main.h"
/**
 * collectPathVariables - function to store path variables
 * @pathArray: array of paths
 * @pathCount: number of paths stored
 * @envp: environment variable
 */
void collectPathVariables(char ***pathArray, int *pathCount, char *envp[])
{
	int i, count = 0;
	char *pathEnv = NULL, *token, copyPath[512], cpPath[512];

	for (i = 0; envp[i] != NULL; i++)
	{
		if (strncmp(envp[i], "PATH=", 5) == 0)
		{pathEnv = envp[i] + 5;
			break;
		}
	}
	strcpy(copyPath, pathEnv);
	strcpy(cpPath, pathEnv);
	if (pathEnv == NULL)
	{fprintf(stderr, "PATH environment variable is not set.\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(copyPath, ":");
	while (token != NULL)
	{count++;
		token = strtok(NULL, ":");
	}
	*pathArray = (char **)malloc(count * sizeof(char *));
	if (*pathArray == NULL)
	{fprintf(stderr, "Memory allocation failed.\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(cpPath, ":");
	for (i = 0; i < count; i++)
	{(*pathArray)[i] = strdup(token);
		if ((*pathArray)[i] == NULL)
		{fprintf(stderr, "Memory allocation failed.\n");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, ":");
	}
	*pathCount = count;
}


/**
 * checkPath - check if path exists
 * @argv: user generated tokens
 * @env: environment variables
 * @progname: exe. program name
 * Return: 0
 */
int checkPath(char *argv[], char *progname[], char **env)
{
	int pathCount, i, pathFound = 0;
	char **pathArray, appendPath[512], *saveValidPath = NULL;
	(void)argv;
	(void)progname;

	collectPathVariables(&pathArray, &pathCount, env);

	for (i = 0; i < pathCount; i++)
	{
		snprintf(appendPath, sizeof(appendPath), "%s/%s", pathArray[i], argv[0]);
		if (access(appendPath, F_OK) == 0)
		{
			saveValidPath = appendPath;
			pathFound = 1;
			execFilePath(argv, progname, env, saveValidPath);
			break;
		}
	}
	for (i = 0; i < pathCount; i++)
	{
		free(pathArray[i]);
	}
	free(pathArray);
	if (!pathFound)
	{
		perror(progname[0]);
		pathFound  = 0;
	}

	return (0);
}

/**
 * cmdn - performs strtok function
 * @buffer: parameter
 * @pgname: exe. program name
 * @envp: environment variables
 * Return: 0
 */
int cmdn(char *buffer, char *pgname[], char **envp)
{
	char *token, *tokens[512];
	int count = 0, i;

	token = strtok(buffer, " ");
	while (token != NULL && count < 512)
	{
		tokens[count] = strdup(token);
		token = strtok(NULL, " ");
		count++;
	}
	tokens[count] = NULL;
	if (access(tokens[0], F_OK) == 0)
		execFilePath(tokens, pgname, envp, NULL);
	else
		checkPath(tokens, pgname, envp);
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
 * @userInput: users input from terminal freed on exit of program
 * Return: returns 0 on success
 */
int end(int read, char *userInput)
{
	if (read == -1)
	{
		free(userInput);
		return (0);
	}
	return (0);
}




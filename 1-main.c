#include "main.h"
#include <stdio.h>


/**
 * main - main function
 * @argc: n number of arguments passed
 * @argv: an array of arguments
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int checkInputPath;
	char buffer[256];
	(void)argc;

	while (1)
	{
		size_t index = 0;
		char str;

		checkInputPath = isatty(STDIN_FILENO);
		
		if (checkInputPath == 1)
		{
			welcome();
			while ((str = my_getchar()) != EOF && str != '\n')
				buffer[index++] = str;
		}
		else
		{
			while ((str = customGetchar()) != EOF)
				buffer[index++] = str;
			printstdout("\n");
		}
		
		if (str == -1)
		{
			return (0);
			printstdout("\n");
		}

		if (strcmp(buffer, "exit") == 0)
			return (0);

		cmdn(buffer, argv);

		/*fflush(stdout);
		for (index = 0; buffer[index]; ++index)
			buffer[index] = 0;*/
	}
	return (0);
}


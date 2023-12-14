#include "main.h"

/**
 * main - main function
 * @argc: n number of arguments passed
 * @argv: an array of arguments
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int checkInputPath;
	(void)argc;

	while (1)
	{
		size_t index = 0;
		char buffer[256], str;

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
			_putchar('\n');
		}

		if (str == -1)
		{
			return (0);
			_putchar('\n');
		}

		if (strcmp(buffer, "exit") == 0)
			return (0);

		cmdn(buffer, argv);
	}
	return (0);
}


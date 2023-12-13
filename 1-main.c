#include "main.h"

/**
* main - main function
* Return: 0
*/

int main(void)
{
	while (1)
	{
		size_t index = 0, i;
		char buffer[256], str;

		welcome();

		while ((str = my_getchar()) != EOF && str != '\n')
			buffer[index++] = str;

		if (str == -1)
			return (0);

		cmdn(buffer);

		for (i = 0; buffer[i]; i++)
			buffer[i] = 0;
	}
	return (0);
}

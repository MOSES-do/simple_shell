#include "main.h"

/**
 * _realloc - Function expands buffer when called
 * @buffer: bag of current values to be expanded
 * @n: new size to be allocated
 * Return: returns a pointer to the expanded buffer
 */

char *_realloc(char *buffer, size_t n)
{
	char *ptr, *oldbuffer;
	int i;

	if (buffer == NULL)
	{
		ptr = malloc(n);
		return (ptr);
	}


	if (buffer == 0)
	{
		free(buffer);
		return (NULL);
	}
	else
	{
		oldbuffer = buffer;

		ptr = malloc(n);

		for (i = 0; buffer[i]; i++)
			ptr[i] = oldbuffer[i];
	}

	free(buffer);

	return (ptr);
}


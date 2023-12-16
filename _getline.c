#include "main.h"

/**
 * _getline - function returns buffer of text frfom terminal
 * @bufclone: pointer to userinput
 * @n: length of buffer
 * @fd: userinput channel
 * Return: length of buffer
 */

ssize_t _getline(char **bufclone, size_t *n, FILE *fd)
{
	size_t MAX_LEN, CUR_LEN, NEW_LEN;
	int c;
	char *buffer;

	if (bufclone == NULL || n == NULL || fd == NULL)
		return (-1);

	*n = 0;
	MAX_LEN =300, NEW_LEN = 300, CUR_LEN = 0;

	buffer = malloc(sizeof(char) * MAX_LEN);
	if (buffer == NULL)
		return (-1);
	while ((c = read(fileno(fd), buffer + CUR_LEN, 1)) > 0)
	{	
		CUR_LEN += c;
		if (CUR_LEN == MAX_LEN)
		{	NEW_LEN *= 2;
			buffer = realloc(buffer, NEW_LEN);
			if (buffer == NULL)
			{
				free(buffer);
				return (-1);
			}
		}
		if (buffer[CUR_LEN - 1] == '\n')
		{	buffer[CUR_LEN - 1] = '\0';
			break;
		}
	}
	MAX_LEN = NEW_LEN;
	if (c == 0 && CUR_LEN > 0)
		*n = CUR_LEN;
	*bufclone = buffer;
	*n = CUR_LEN;
	(*n)--;
	return (*n);
}


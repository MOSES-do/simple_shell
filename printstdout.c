#include "main.h"

/**
 * printstdout - Prints by referencing the standard file number
 * @string: takes in a string to print
 **/

void printstdout(const char *string)
{
	write(STDOUT_FILENO, string, strlen(string));
}


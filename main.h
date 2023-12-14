#ifndef MAIN_H
#define MAIN_H
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#define MAX_SIZE 1024

int _putchar(char c);
void printstdout(const char *string);
int welcome(void);
int cmdn(char *buffer, char *pgname[]);
int checkPath(char *argv[], char *progname[]);
int execFilePath(char *argv[], char *pgname[]);
int end(int);

#endif


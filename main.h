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

int welcome(void);
int cmdn(char *buffer);
int execFilePath(char *argv[]);
int my_getchar(void);
int AnotherexecFilePath(char *argv[]);
int Anothercmdn(char *buffer);
#endif

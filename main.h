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
int cmdn(char *buffer, char *pgname[], char **envp);
int checkPath(char *argv[], char *progname[], char **env);
int execFilePath(char *argv[], char *pgname[], char **env);
int end(int, char*);
char *_realloc(char *buffer, size_t n);
ssize_t _getline(char **bufclone, size_t *n, FILE *fd);
#endif


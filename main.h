#ifndef MAIN_H
#define MAIN_H
#include <stdio.>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>

void _strtok(char *p, char **tokens);
void _execvp(const char *file, char *const argv[]);
char *_getenv(char *name);
void _strcpy(char *des, const char *src);
void _strcat(char *des, const char *src);
int _strcmp(const char *st1, const char *st2);
void print_environment(void);
void _putchar(char c);
#endif

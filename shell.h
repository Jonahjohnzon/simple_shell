#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>

int _putchar(char c);
char *_getenv(const char *name);
char **_strtok(char *str, const char *delim);
void _exec(char **argv);
void _print_word(char *str);
void(*_checkers(char **arvg))(char **arvg);
char _strtok(char *str, const char *delim);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void freearvg(char **arvg);
char *_which(char *file, list_path *head);

extern char **environ;
typedef struct list_p
{
	char *dir;
	struct list_p *p;
} list_p;

typedef struct mybuild
{
	char *name;
	void (*func)(char **);
} _build;

list_p *linkp(char *path);
#endif


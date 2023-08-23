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
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void freearvg(char **arvg);
void _exitnow(char **arvg);
void env(char **arv);

extern char **environ;
/**
 * struct list_p - linked list
 * @dir: directory
 * @p: point to next
 */
typedef struct list_p
{
	char *dir;
	struct list_p *p;
} list_p;

char *_which(char *file, list_p *head);
list_p *linkp(char *path);
list_p *add_node_end(list_p **head, char *str);
/**
 * struct _build - linked list
 * @namer: build
 * @func: execute
 */
typedef struct _build
{
	char *name;
	void (*func)(char **);
} _build;

#endif


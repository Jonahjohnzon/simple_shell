#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2
#define USE_GETLINE 0
#define USE_STRTOK 0
#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;
/**
 * struct listst - singly
 * @num: input
 * @str: string
 * @next: next node
 */
typedef struct listst
{
	int num;
	char *str;
	struct liststr *next;
} list_table;
/**
 *struct passinfo - pseudo-arguements to pass into a function
 *@arg: a string generated from getline
 *@argv: strings generated from arg
 *@path: string path
 *@argc: argument count
 *@line_count: error count
 *@err_num: the error exit()s
 *@linecount_flag: input
 *@fname: the program file
 *@env: environ
 *@environ: custom modified
 *@history: the history
 *@alias: the alias
 *@env_changed: on if environ 
 *@status: the return status
 *@cmd_buf: address of pointer
 *@cmd_buf_type: CMD_types
 *@readfd: the fd
 *@histcount: the history
 */
typedef struct passin
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_table *env;
	list_table *history;
	list_table *alias;
	char **environ;
	int env_changed;
	int status;
	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_table;
#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}
ssize_t input_buff(info_table *info, char **buff, size_t *len);
ssize_t _input(info_table *info);
int _getline(info_table *inform, char **pt, size_t *leng);
void ctrl_Handler(__attribute__((unused))int sig);
#endif

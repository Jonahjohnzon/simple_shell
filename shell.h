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
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_table;
/**
 *struct passin - pseudo-arguement
 *@arg: from getline
 *@argv:from arg
 *@path: string paths
 *@argc: argument counts
 *@line_count: error counts
 *@err_num: the error exit
 *@linecount_flag: inputs
 *@fname: the program files
 *@env: environment
 *@environ: custom modify
 *@history: the historys
 *@alias: the aliass
 *@env_changed: on if environment
 *@status: the return statues
 *@cmd_buf: address of pointers
 *@cmd_buf_type: CMD_type
 *@readfd: the fds
 *@histcount: the historys
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
/**
 *struct built - built-in
 *@type: input
 *@func: input
 */
typedef struct built
{
	char *type;
	int (*func)(info_table *);
} built_table;

size_t list_l(const list_table *h);
char **list_to_strings(list_table *heads);
char *get_history_file(info_table *info);
int write_history_event(info_table *info);
int read_event(info_table *info);
int build_event_list(info_table *info, char *buf, int linecount);
int renumber_event(info_table *info);
int env_list(info_table *inform);
ssize_t input_buff(info_table *info, char **buff, size_t *len);
ssize_t _input(info_table *info);
int _getline(info_table *inform, char **pt, size_t *leng);
void ctrl_Handler(__attribute__((unused))int sig);
int _free(void **loc);
int _cmd(info_table *info, char *location);
char *_dup(char *path, int a, int b);
char *_path(info_table *info, char *paths, char *cmd);
char *_strcpy(char *des, char *src);
char *_strdup(const char *str);
int _putchar(char c);
int _strlen(char *str);
int _strcmp(char *str1, char *str2);
char *_begin_with(const char *str_a, const char *str_b);
char *_strcat(char *des, char *src);
int _env(info_table *info);
char *_getenv(info_table *info, const char *name);
int r_string(char **o, char *n);
int r_vars(info_table *info);
int r_alias(info_table *info);
int _chain(info_table *info, char *buff, size_t *p);
void chek_chain(info_table *info, char *buff, size_t *p, size_t i, size_t len);
int interactive(info_table *dets);
int is_delim(char c, char *del);
int _isalpha(int c);
int _atoi(char *str);
void _puts(char *str);
char **strtow(char *str, char *del);
char **str_tow(char *str, char del);
void fork_c(info_table *inform);
int find_built(info_table *inform);
int _app(info_table *inform, char **a);
size_t print_list(const list_table *value);
list_table *node_starts_with(list_table *nodes, char *pre, char c);
ssize_t get_node_index(list_table *head, list_table *nodes);
char *_strncpy(char *des, char *src, int n);
char *_strncat(char *str1, char *str2, int b);
char *_strchr(char *str, char c);
int _errputchar(char c);
void _errputs(char *str);
int _putfdr(char c, int fdr);
int _putsfdr(char *str, int fdr);
void free_info(info_table *inform, int all);
void set_inf(info_table *inform, char **av);
void cl_info(info_table *inform);
char **get_envi(info_table *inform);
void find_c(info_table *inform);
int _mhelp(info_table *inform);
int _mcd(info_table *inform);
int _mexit(info_table *inform);
char *_memset(char *str, char b, unsigned int n);
void ffree(char **ss);
void *_realloc(void *ptr, unsigned int past_size, unsigned int built_size);
int print_d(int input, int f);
void print_err(info_table *inform, char *str);
int _eratoi(char *a);
void remove_comment(char *buff);
char *convert_number(long int num, int base, int flag);
void free_list(list_table **head_);int delete_node_(list_table **head, unsigned int ind);
size_t print_list_s(const list_table *v);
list_table *add_node_(list_table **heads, const char *st, int num);
list_table *_addnode(list_table **heads, const char *st, int num);
int _setenv(info_table *info, char *var, char *value);
int _unsetenv(info_table *info, char *var);
#endif

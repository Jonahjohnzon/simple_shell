#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <limits.h>

#define HIST_F  ".simple_shell_history"
#define READ_BUF_ 1024
#define CMD_O           1
#define B_FLUSH -1
#define CMD_NO	0
#define WRITE_BUF_ 1024
#define CMD_A		2
#define CONVERT_UNS	2
#define USE_GETL 0
#define CMD_CHA 3
#define USE_STR 0
#define HIST_M	4096
#define CONVERT_LOWER   1

extern char **environ;
/**
 * struct liststr - singly
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
 *@argvv:from arg
 *@pathe: string paths
 *@err_num: the error exit
 *@argcs: argument counts
 *@args: from getline
 *@line_count: error counts
 *@linecount_flag: inputs
 *@fnames: the program files
 *@envi: environment
 *@enviro: custom modify
 *@historys: the historys
 *@cmd_buff: address of pointers
 *@alias: the aliass
 *@status: the return statues
 *@cmd_buff_type: CMD_type
 *@env_change: on if environment
 *@readfdd: the fds
 *@histcounts: the historys
 */
typedef struct passin
{
	char *args;
	unsigned int line_count;
	char **argvv;
	int argcs;
	int err_num;
	char *pathe;
	char *fnames;
	list_table *envi;
	list_table *alias;
	int linecount_flag;
	char **enviro;
	int env_change;
	list_table *historys;
	int status;
	char **cmd_buff;
	int readfdd;
	int cmd_buff_type;
	int histcounts;
} info_table;
#define INFO_INIT \
{ \
	NULL, 0, NULL, 0, 0, NULL, NULL, NULL, NULL, 0, NULL, 0, NULL, 0, NULL, \
	0, 0, 0 \
}
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
void free_list(list_table **);
int delete_node_(list_table **, unsigned int ind);
size_t print_list_s(const list_table *v);
list_table *add_node_(list_table **heads, const char *st, int num);
list_table *_addnode(list_table **heads, const char *st, int num);
int _setenv(info_table *info, char *var, char *value);
int _unsetenv(info_table *info, char *var);
int _myhistory(info_table *info);
int unset_alias(info_table *info, char *str);
int set_alias(info_table *info, char *str);
int print_alias(list_table *node);
int _myalias(info_table *info);
int _seten(info_table *inform);
int _unseten(info_table *inform);
#endif

#ifndef  _MAIN_H_
#define  _MAIN_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>

#define TOK_BUFSIZE 128
#define BUFSIZE 1024
#define TOK_DELIM " \t\r\n\a"

/* Points to an array of pointers to strings called the "environment" */
extern char **env;


/**
 * struct data - struct  contains all the relevant data on runtime
 * @av: argument vector
 * @input: command line written by user
 * @args: tokens of the command lines
 * @status: last status of shell
 * @counter: line counters
* @_env: environment variable
 * @pid: process ID of shell
 */
typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_env;
	char *pid;
} data_shell;

/**
 * struct sep_list_s - single linked list
 * @separator: ; | &
 * @next: next node
 * Description: single linked list that stores separators
 */
typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_list;

/**
 * struct line_list_s - single linked list
 * @line: command line
 * @next: next node
 * Description: single linked list that store command line
 */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;

/**
 * struct r_var_list - single linked list
 * @len_var: length of variable
 * @val: value of variable
 * @len_val: length of whole value
 * @next: next node
 * Description: single linked list that store variables
 */
typedef struct r_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_list *next;
} r_var;

/**
 * struct builtin_s - Builtin struct for the command args.
 * @name: The name of the command builtin i.e cd, exit, env, help
 * @f: data type pointer function.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(data_shell *datash);
} builtin_t;

/* directory.c */
void cd_dot(data_shell *datash);
void cd_to(data_shell *datash);
void cd_previous(data_shell *datash);
void cd_to_home(data_shell *datash);

/* cd_dir.c */
int cd_shell(data_shell *datash);

/* separator.c */
sep_list *add_sep_node_end(sep_list **head, char sep);
void free_sep_list(sep_list **head);
line_list *add_line_node_end(line_list **head, char *line);
void free_line_list(line_list **head);

/* bettycheck.c */
int main(void)

/* _exit.c */
int exit_shell(data_shell *datash);

#endif

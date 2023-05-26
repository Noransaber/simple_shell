#ifndef SHELL_H
#define SHELL_H

#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#define PATH_FOUND 1
#define PATH_NOT_FOUND 0
#define _GNU_SOURCE

int handle_command(char *command, char *envp[]);

void handle_input(char *input, char *envp[]);

#define PIPELINE_MAX_COMMANDS 2
#define MAX_COMMANDS 10

char **parse_pipeline_commands(char *pipeline, int *num_commands);

int my_pipline_handler(char *pipeline, char *envp[]);

void handle_error(const char *message);

void do_hard_things(void);

pid_t create_my_child(int *myinput_fd);

void command_execution(char *my_cmd);

int sys_cust(char *my_cmd, int in_fd);

int wait_for_my_child(pid_t my_child);

int create_pipes(int pipefd[][2], int num_pipes);

void free_commands(char *commands[], int num_commands);

void execute_commands(char *commands[], int num_commands,
		int pipefd[][2], char *envp[]);

void close_pipes(int pipefd[][2], int num_pipes);

void wait_for_children(int num_commands);

int run_shell(char *pipeline, char *envp[]);

char *my_substr(char *sentence, char *word);

pid_t fork_execute_function(char **array_string, char *env[]);

char **string_tokenization(char *str);

int my_strcmp(const char *string1, const char *string2);

char *my_dubler(char *str);

int my_strlen(char *str);

int path_check_function(char *final_string);

char *file_check(char *final_string);

ssize_t read_input(char **line_input, size_t *size_input);

char *my_strcpy(char *to, char *from);

int check_build_in_func(char *final_string, char *envp[]);

char *my_strcat(const char *str1, const char *str2);

int my_env(void);

void my_exit(char **argument);

int my_atoi(char *my_string);

void handle_non_terminal_input(void);

#endif

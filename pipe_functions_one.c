#include "shell.h"
/**
 * handle_error - handle error of piplines
 * @message: meesage error
 * Return: nothing, void
**/
void handle_error(const char *message)
{
	fprintf(stderr, "%s\n", message);
}
/**
 * close_pipes - close the pipes
 * @pipefd: file describtor for the pipe
 * @num_pipes: number of pipes
 * Return: nothing
**/
void close_pipes(int pipefd[][2], int num_pipes)
{
	int i;

	for (i = 0; i < num_pipes; i++)
	{
		close(pipefd[i][0]);
		close(pipefd[i][1]);
	}
}
/**
 * wait_for_children - handle waiting for child proccess
 * @num_commands: take number of commands
 * Return: nothing
**/
void wait_for_children(int num_commands)
{
	int i;

	for (i = 0; i < num_commands; i++)
	{
		wait(NULL);
	}
}

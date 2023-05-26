#include "shell.h"
/**
 * run_shell - handle breaking down the commands, excution of the cmd
 * hanlde closing the cmd, wait, free cmds
 * @pipeline: line input from the user
 * @envp: array of env var
 * Return: 0 on success
**/
int run_shell(char *pipeline, char *envp[])
{
	int num_commands = 0, i;
	int pipefd[MAX_COMMANDS - 1][2];
	char *commands[MAX_COMMANDS];
	char *token;

	token = strtok(pipeline, "|");
	while (token != NULL && num_commands < PIPELINE_MAX_COMMANDS)
	{
		commands[num_commands++] = token;
		token = strtok(NULL, "|");
	}
	if (num_commands < 2)
	{
		handle_error("Invalid pipeline command");
		return (1);
	}
	for (i = 0; i < num_commands - 1; i++)
	{
		if (pipe(pipefd[i]) == -1)
		{
			perror("pipe");
			handle_error("Failed to create pipe");
			return (1);
		}
	}
	execute_commands(commands, num_commands, pipefd, envp);
	close_pipes(pipefd, num_commands - 1);
	wait_for_children(num_commands);
	return (0);
}

#include "shell.h"
/**
 * execute_commands - perform every single cmd in pipline
 * @commands: pipline commands array
 * @num_commands: commands count in the pipeline
 * @pipefd: pip fd array
 * @envp: enviromental variable array
 * Return: nothing
**/
void execute_commands(char *commands[], int num_commands,
		int pipefd[][2], char *envp[])
{
	int i;

	for (i = 0; i < num_commands; i++)
	{
		pid_t pid = fork();

		if (pid == -1)
		{
			perror("fork");
			handle_error("Failed to create child process.");
			exit(1);
		}
		if (pid == 0)
		{
			if (i == 0)
			{
				dup2(pipefd[i][1], STDOUT_FILENO);
			}
			else if (i == num_commands - 1)
			{
				dup2(pipefd[i - 1][0], STDIN_FILENO);
			}
			else
			{
				dup2(pipefd[i - 1][0], STDIN_FILENO);
				dup2(pipefd[i][1], STDOUT_FILENO);
			}
			close_pipes(pipefd, num_commands - 1);
			exit(handle_command(commands[i], envp));
		}
	}
}

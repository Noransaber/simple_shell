#include "shell.h"
/**
 * fork_execute_function - perform(exe)the program in a child process
 * @array_string: the line input from the user in array
 * @env: parent array environmental variable
 * Return: void
 */
void fork_execute_function(char **array_string, char *env[])
{
	pid_t my_child_pid;
	int waiting_status;

	my_child_pid = fork();
	if (my_child_pid < 0)
	{
		perror("Error: Fork failed");
		return;
	}
		if (my_child_pid == 0)
		{
			if (execve(array_string[0], array_string, env) == -1)
		{
			fprintf(stderr, "./shell: %s: No file or directory\n", array_string[0]);
			_exit(EXIT_FAILURE);
		}
	}
		else
	{
	if (wait(&waiting_status) == -1)
	{
		perror("Error: Wait failed");
	}
	}
}

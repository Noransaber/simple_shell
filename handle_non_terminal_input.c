#include "shell.h"
/**
 * handle_non_terminal_input - handle any input from non terminal
 * @envp: the env variables
 * Return: nothing
 **/
void handle_non_terminal_input(void)
{
	char input[100];
	ssize_t char_read;
	int pipe_fd[2];

	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	while ((char_read = read(STDIN_FILENO, input, sizeof(input))) > 0)
	{
		input[strcspn(input, "\n")] = '\0';
		if (write(pipe_fd[1], input, my_strlen(input)) == -1)
		{
			perror("write");
			exit(EXIT_FAILURE);
		}
		sys_cust(input, pipe_fd[0]);
	}
	close(pipe_fd[1]);
	close(pipe_fd[0]);
}


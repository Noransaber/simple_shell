#include "shell.h"
/**
 * main - entry point to the program
 * @argc: the number of arguments
 * @argv: array of arguments
 * @envp: array of environmental variables
 * Return: Exit SUCCESS
 **/
int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	if(isatty(STDIN_FILENO))
	{
		char *u_input_line;
		size_t input_size_line = 0;
		ssize_t char_read;

		while (1)
		{
			printf(";) ");
			u_input_line = NULL;
			char_read = read_input(&u_input_line, &input_size_line);

			if (char_read < 0)
			{
				perror("read)input");
				free(u_input_line);
				continue;
			}
			if (*u_input_line != '\n')
			{
				sys_cust(u_input_line, STDIN_FILENO);
			}
			free(u_input_line);
		}
	}
	else
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
exit(EXIT_SUCCESS);
}

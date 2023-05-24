#include "shell.h"
/**
 * main - the entry point of the program
 * @argc: represent the count of argimants we recieve
 * @argv: vector, array of arguments
 * @envp: array of enviromental vaiables
 * Return: integer number represet the success of the program
 **/
int main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;
	if (isatty(STDIN_FILENO))
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
		perror("read_input");
		free(u_input_line);
		continue;
	}
		if (*u_input_line != '\n')
		{
			handle_input(u_input_line, envp);
		}
	free(u_input_line);
	}
	}
	else
	{
	char input[100];
	ssize_t char_read;

	while ((char_read = read(STDIN_FILENO, input, sizeof(input))) > 0)
	{
		input[strcspn(input, "\n")] = '\0';
		handle_input(input, envp);
	}
	}

	exit(EXIT_SUCCESS);
}

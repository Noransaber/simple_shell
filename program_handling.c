#include "shell.h"
/**
 * create_my_child - create child process
 * @myinput_fd: file describtor for the input
 * Return: 0 on child, positive on parent
 **/
pid_t create_my_child(int *myinput_fd)
{
	pid_t my_pid;

	my_pid = fork();
	if (my_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (my_pid == -1)
	{
		if (dup2(*myinput_fd, STDIN_FILENO) == -1)
		{
			perror("dup2");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	else
	{
		return (my_pid);
	}
}

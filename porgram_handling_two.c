#include "shell.h"
/**
 * command_execution - excute the cmd
 * @my_cmd: the command
 * Return: nothind
 **/
void command_execution(char *my_cmd)
{
	char *argv[4];

	argv[0] = "sh";
	argv[1] = "-c";
	argv[2] = my_cmd;
	argv[3] = NULL;

	execvp("/bin/sh", argv);
	perror("execvp");
	exit(EXIT_FAILURE);
}
/**
 * sys_cust - interface to excute the cmd
 * @my_cmd: take the command
 * @in_fd: file describtor for it
 * Return: exit_status
 */
int sys_cust(char *my_cmd, int in_fd)
{
	int exit_stat;
	pid_t my_child = create_my_child(&in_fd);

	if (my_child == 0)
	{
		command_execution(my_cmd);
	}
	exit_stat = wait_for_my_child(my_child);
	return (exit_stat);
}

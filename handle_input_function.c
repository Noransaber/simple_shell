#include "shell.h"
/**
 * handle_input - ask if the input has | it calls the func to handle it
 * if it doesn't have it call handle command function
 * @input: line_input which we are searching in it
 * @envp: enviromantal variable
 * Return: Nothing
*/
void handle_input(char *input, char *envp[])
{
	if (my_substr(input, "|"))
	{
		run_shell(input, envp);
	}
	else
	{
		handle_command(input, envp);
	}
}

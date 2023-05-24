#include "shell.h"

/**
 * check_build_in_func - checking a built in function
 * @final_string: input from user
 * @envp: array of evironmental variables
 * Return: return an integer value
 */

int check_build_in_func(char *final_string, char *envp[])
{
	char *array_buitin[] = {"cd", "exit", "env"};
	int num_builtins = sizeof(array_buitin) / sizeof(array_buitin[0]);

	for (int f = 0; f < num_builtins; f++)
	{
	if (my_strcmp(array_buitin[f], final_string) == 0)
	{
		switch (f + 1)
		{
		case 1:
			chdir(final_string);
			return (1);
		case 2:
			printf("BYE ;)");
			return (2);

		case 3:
			my_env(envp);
			return (1);

		default:
			return (0);
		}
	}
	}

	return (0);
}

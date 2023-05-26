#include "shell.h"
/**
 * my_env - it prints the environmental value
 * Return: return 0 success
 */
int my_env(void);
/**
 * check_build_in_func - checking the string built in function
 * @final_string: input from user
 * @envp: array for environmental variables
 * Return: return an integer value
 */
int check_build_in_func(char *final_string, char *envp[])
{
	char *array_buitin[] = {"cd", "exit", "env"};
	int num_builtins = sizeof(array_buitin) / sizeof(array_buitin[0]);
	int f;
	(void)envp;

	for (f = 0; f < num_builtins; f++)
	{
	if (my_strcmp(array_buitin[f], final_string) == 0)
	{
		switch (f + 1)
		{
		case 1:
			chdir(final_string);
			return (1);

		case 2:
			exit(EXIT_SUCCESS);

		case 3:
			my_env();
			return (1);

		default:
			return (0);
		}
	}
	}

	return (0);
}

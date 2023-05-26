#include "shell.h"
/**
 * path_check_function - check if the command has the path /bin/
 * @final_string: line input token from the line input
 * Return: 1 if the path is found, 0 if false
 */
int path_check_function(char *final_string)
{
	char *my_comparing_path = "/bin/";
	int my_counter = 0, my_index = 0;
	char *result_to_cmp, *command_to_check;

	result_to_cmp = malloc((my_strlen(final_string) + 1) * sizeof(char));
	if (result_to_cmp == NULL)
	{
		perror("Error: Memory allocation failed");
		return (0);
	}
	while (my_comparing_path[my_counter] != '\0')
	{
		if (my_comparing_path[my_counter] != final_string[my_counter])
		{
			free(result_to_cmp);
			return (0);
		}
		my_counter++;
	}
	while (final_string[my_counter] != '\0')
	{
		result_to_cmp[my_index] = final_string[my_counter];
		my_index++;
		my_counter++;
	}
	result_to_cmp[my_index] = '\0';
	command_to_check = file_check(result_to_cmp);

	if (command_to_check != NULL)
	{
		free(result_to_cmp);
		return (PATH_FOUND);
	}
	free(result_to_cmp);
	return (PATH_NOT_FOUND);
}

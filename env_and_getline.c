#include "shell.h"
/**
 * read_input -  from stdin using getline
 * @line_input: Pointer to store the input line
 * @size_input: Pointer to store the size of allocated memory
 * Return: num of characters read (-1 if error)
 */
ssize_t read_input(char **line_input, size_t *size_input)
{
	ssize_t char_read = getline(line_input, size_input, stdin);

	if (char_read == -1)
	{
		perror("Error: Failed to read input");
		exit(EXIT_FAILURE);
	}
		return (char_read);
}


/**
* my_env - print the environmental variables of the shell
* Return: 1
**/
int my_env(void)
{
	int my_counter = 0;

	while (environ[my_counter] != NULL)
	{
		printf("%s\n", environ[my_counter]);
		my_counter++;
	}
	return (1);
}

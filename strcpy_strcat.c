#include "shell.h"
/**
 * my_strcpy - cp str
 * @to_dest: the destination
 * @from_scr: the source
 *
 * Return: pointer to destination
 */
char *my_strcpy(char *to_dest, char *from_scr)
{
	int my_counter = 0;

	if (to_dest == from_scr || from_scr == 0)
		return (to_dest);
	while (from_scr[my_counter])
	{
		to_dest[my_counter] = from_scr[my_counter];
		my_counter++;
	}
	to_dest[my_counter] = 0;
	return (to_dest);
}
#include "shell.h"
/**
 * my_strcat - function concatenate two strings togwther
 * @str1: sstring one
 * @str2: string two
 * Return: pointer to variable
 */
char *my_strcat(const char *str1, const char *str2)
{
	size_t strlength1 = strlen(str1);
	size_t strlength2 = strlen(str2);
	char *container = malloc(strlength1 + strlength2 + 1);

	if (container == NULL)
	{
		return (NULL);
	}
	strcpy(container, str1);
	strcpy(container + strlength1, str2);
		return (container);
}

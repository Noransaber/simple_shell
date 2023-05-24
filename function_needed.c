#include "shell.h"
/**
 * my_dubler - like the fork, i separate the string into two
 * @str: string to be devided into two
 * Return: pointer to my_dubler string
 */
char *my_dubler(char *str)
{
	int mystr_length = 0;
	char *my_dub;

	if (str == NULL)
		return (NULL);
	while (*str++)
		mystr_length++;
	my_dub = malloc(sizeof(char) * (mystr_length + 1));
	if (!my_dub)
		return (NULL);
	for (mystr_length++; mystr_length--;)
		my_dub[mystr_length] = *--str;
	return (my_dub);
}

#include "shell.h"
/**
 * my_strlen - count the num of charater in the str
 * @str: string to be checked
 * Return: length of str
 */
int my_strlen(char *str)
{
	int my_counter = 0;

	if (!str)
		return (0);
	while (*str++)
		my_counter++;
	return (my_counter);
}

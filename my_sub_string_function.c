#include "shell.h"
/**
 * my_substr - it's like searching on a word in sentence
 * @sentence: the first param and where we are searching in
 * @word: the part which we are searching about
 * Return: pointer to the address where we find that word in the sent
*/
char *my_substr(char *sentence, char *word)
{
	int my_s;

	for (my_s = 0; sentence[my_s] != '\0'; my_s++)
	{
		if (sentence[my_s] == word[0])
		{
		int my_w;

		for (my_w = 0; word[my_w] != '\0'; my_w++)
		{
			if (sentence[my_s + my_w] != word[my_w])
			{
				break;
			}
		}

			if (word[my_w] == '\0')
			{
				return (&sentence[my_s]);
			}
		}
	}
	return (NULL);
}

#include "shell.h"
/**
 * file_check - check if the command file exists in /bin/
 * @final_string: input line from user to check
 * Return: NULL if not found, otherwise the full path to the command
 */
char *file_check(char *final_string)
{
	DIR *in_dir = opendir("/bin/");
	struct dirent *entir_struct;

	if (in_dir == NULL)
	{
		perror("opendir");
		return (NULL);
	}


	while ((entir_struct = readdir(in_dir)) != NULL)
	{
		char *dir_container = entir_struct->d_name;

		if (strcmp(dir_container, final_string) == 0)
	{
		char *cmd_exist = malloc(my_strlen("/bin/") + my_strlen(final_string) + 1);

	if (cmd_exist == NULL)
	{
		closedir(in_dir);
		perror("malloc");
		return (NULL);
	}
		cmd_exist = strcpy(cmd_exist, "/bin/");
		cmd_exist = my_strcat(cmd_exist, final_string);
		closedir(in_dir);
		return (cmd_exist);
	}
	}

		closedir(in_dir);
	return (NULL);
}

#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * command_exists - Check if the command exists in the directories in PATH
 * @cmd: The command to check.
 *
 * Return: 1 if command exists, 0 otherwise.
 */
int command_exists(char *cmd)
{
	char *path_env = getenv("PATH");
	char *path_copy;
	char *dir;
	struct stat buf;

	if (path_env == NULL)
		return (0);

	path_copy = malloc(strlen(path_env) + 1);
	if (path_copy == NULL)
		return (0);

	strcpy(path_copy, path_env);
	dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
		char full_path[256];

		snprintf(full_path, sizeof(full_path), "%s/%s", dir, cmd);

		if (stat(full_path, &buf) == 0 && (buf.st_mode & S_IXUSR))
		{
			free(path_copy);
			return (1);
		}

		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (0);
}

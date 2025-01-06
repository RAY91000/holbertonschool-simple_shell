#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "shell.h"

/**
 * command_exists - Check if the command exists in the directories in PATH
 * @cmd: The command to check.
 *
 * Return: 1 if command exists, 0 otherwise.
 */

int command_exists(char *cmd)
{
	char *path_env = getenv("PATH");
	char *path_copy = strdup(path_env);
	char *dir = strtok(path_copy, ":");
	struct stat buf;

	if (path_env == NULL)
	{
		return (0);
	}

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

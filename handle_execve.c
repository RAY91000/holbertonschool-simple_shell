#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

/**
 * handle_execve - Executes the command if it's valid.
 * @argv: Array of arguments.
 *
 * Return: 1 if executed successfully, 0 otherwise.
 */
int handle_execve(char **argv)
{
	struct stat buf;

	if (argv[0][0] == '/')
	{
		if (stat(argv[0], &buf) == 0 && (buf.st_mode & S_IXUSR))
		{
			execve(argv[0], argv, environ);
			perror("execve failed");
			return (0);
		}
		else
		{
			perror(argv[0]);
			return (0);
		}
	}
	else if (command_exists(argv[0]))
	{
		execve(argv[0], argv, environ);
		perror("execve failed");
		return (1);
	}
	return (0);
}

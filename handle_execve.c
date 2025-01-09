#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * handle_execve - Executes the command if it's valid.
 * @argv: Array of arguments.
 *
 * Return: 1 on success, 0 on failure.
 */
int handle_execve(char **argv)
{
	struct stat buf;

	if (argv[0][0] == '/')
	{
		if (stat(argv[0], &buf) == 0 && (buf.st_mode & S_IXUSR))
		{
			execve(argv[0], argv, environ);
			return (1);  /* Success (although execve won't return unless it fails) */
		}
		else
		{
			/* Command not found error message */
			perror(argv[0]);  /* This prints the message like 'No such file or directory' */
			return (0);  /* Command not found */
		}
	}
	else if (command_exists(argv[0]))
	{
		execve(argv[0], argv, environ);
		return (1);  /* Success */
	}

	return (0);  /* Command not found */
}

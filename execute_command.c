#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * execute_command - Forks and executes a command.
 * @argv: Array of arguments.
 *
 * Return: 1 on success, 0 on failure.
 */
int execute_command(char **argv)
{
	pid_t pid = fork();
	int status;

	if (pid == 0)
	{
		handle_exit(argv);
		handle_echo(argv);

		if (!handle_execve(argv))
		{
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		wait(&status);

		if (WEXITSTATUS(status) != 0)
		{
			fprintf(stderr, "%s: No such file or directory\n", argv[0]);
		}
	}
	else
	{
		perror("fork failed");
		return (0);
	}

	return (1);
}

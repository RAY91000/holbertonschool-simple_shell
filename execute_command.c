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

	if (pid == 0)  /* Child process */
	{
		handle_exit(argv);  /* Check for the exit command. */
		handle_echo(argv);  /* Check for the echo command. */

		if (!handle_execve(argv))  /* Execute the command. */
		{
			/* More user-friendly error message */
			fprintf(stderr, "%s: No such file or directory\n", argv[0]);
			exit(EXIT_FAILURE);  /* Exit the child process with failure. */
		}
	}
	else if (pid > 0)  /* Parent process */
	{
		wait(&status);  /* Wait for the child process to finish. */
	}
	else  /* Fork failed */
	{
		perror("fork failed");
		return (0);
	}

	return (1);  /* Command executed successfully. */
}

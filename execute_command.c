#include "shell.h"

/**
 * execute_command - Function to fork and execute a command using execve.
 * @argv: Array of arguments to pass to execve.
 *
 * Return: 1 if the command executed successfully, otherwise 0.
 */
int execute_command(char **argv)
{
	pid_t pid = fork();
	int status;

	if (pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			perror("Error executing command");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{

		wait(&status);
	}
	else
	{
		perror("fork failed");
		return (0);
	}

	return (1);
}

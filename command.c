#include "shell.h"
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

/**
 * read_command - Reads a command line from standard input.
 * @line: Pointer to the buffer storing the input line.
 * @len: Pointer to the size of the buffer.
 *
 * Return: Number of characters read, or -1 on error.
 */
ssize_t read_command(char **line, size_t *len)
{
	return (getline(line, len, stdin));
}

/**
 * parse_command - Parses a command line into arguments.
 * @line: The command line to parse.
 * @argv: Array to store the arguments.
 */
char **parse_command(char *line)
{
	size_t bufsize = 64, i = 0;
	char **argv = malloc(bufsize * sizeof(char *));
	char *token;

	if (!argv)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " ");
	while (token)
	{
		argv[i++] = token;
		if (i >= bufsize)
		{
			bufsize += 64;
			argv = realloc(argv, bufsize * sizeof(char *));
			if (!argv)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, " ");
	}
	argv[i] = NULL;

	return (argv);
}

/**
 * execute_command - Executes a command using execve.
 * @argv: Array of arguments for the command.
 */
void execute_command(char **argv)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			write(STDERR_FILENO, "Error: Command not found\n", 25);
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
	}
}

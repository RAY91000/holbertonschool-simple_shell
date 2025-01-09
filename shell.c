#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

/**
 * command_exists - Checks if the command exists in the directories listed
 * in the PATH environment variable.
 * @command: The command to check.
 *
 * Return: Full path to the command if found, NULL otherwise.
 */
char *command_exists(char *command)
{
	char *path = getenv("PATH");
	char *dir = strtok(path, ":");
	char full_path[1024];

	if (access(command, F_OK) == 0 && access(command, X_OK) == 0)
	{
		return command;
	}

	while (dir)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);
		if (access(full_path, F_OK) == 0 && access(full_path, X_OK) == 0)
		{
			return strdup(full_path);
		}
		dir = strtok(NULL, ":");
	}

	return NULL;
}

/**
 * execute_command - Executes the given command by creating a new process.
 * @argv: Array of arguments for the command.
 */
void execute_command(char **argv)
{
	pid_t pid;
	int status;
	char *command_path;

	command_path = command_exists(argv[0]);

	if (!command_path)
	{
		write(STDERR_FILENO, "Error: Command not found\n", 25);
		return;
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(command_path, argv, environ) == -1)
		{
			perror("execve failed");
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

	free(command_path);
}

/**
 * readline - Reads a line of input from the user.
 *
 * Return: A pointer to the line entered by the user, or NULL on error.
 */
char *readline(void)
{
	char *buffer = NULL;
	size_t size = 0;

	if (getline(&buffer, &size, stdin) == -1)
	{
		free(buffer);
		return NULL;
	}
	buffer[strcspn(buffer, "\n")] = 0;
	return buffer;
}

/**
 * main_loop - Main loop of the shell that displays the prompt,
 * reads input, and executes the command.
 */
void main_loop(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char *argv[2];

	while (1)
	{
		display_prompt();
		nread = read_command(&line, &len);

		if (nread == -1) /* Handle end-of-file (Ctrl+D) */
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		if (nread > 1) /* Skip empty commands */
		{
			parse_command(line, argv);
			execute_command(argv);
		}
	}

	free(line);
}

/**
 * main - Main function of the shell program.
 * Initializes the main loop.
 *
 * Return: 0 on success.
 */
int main(void)
{
	main_loop();
	return (0);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "shell.h"

#define PROMPT "ツ"

extern char **environ;

/**
 * display_prompt - Function to display custom prompt
 */
void display_prompt(void)
{
	printf("%s", PROMPT);
	fflush(stdout);
}

/**
 * parse_line - Parse the input line into arguments.
 * @line: The input string from the user.
 * @argv: Array to hold parsed arguments.
 *
 * Return: Number of arguments parsed.
 */
int parse_line(char *line, char **argv)
{
	int i = 0;

	argv[i] = strtok(line, " ");
	while (argv[i] != NULL)
	{
		i++;
		argv[i] = strtok(NULL, " ");
	}
	return (i);
}

/**
 * execute_command - Fork a child process to execute the command.
 * @argv: Array of arguments for the command.
 *
 * Return: Nothing.
 */
void execute_command(char **argv)
{
	if (command_exists(argv[0]))
	{
		pid_t pid = fork();
		int status;

		if (pid == 0)
		{
			if (execve(argv[0], argv, environ) == -1)
			{
				perror("Error");
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
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		printf("%s: command not found\n", argv[0]);
	}
}

/**
 * main - Entry point for the program.
 *
 * Return: Always 0 (Success).
 */
int main(void)
{
	char *line = NULL;
	char *argv[64];
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		display_prompt();
		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			free(line);
			printf("\n");
			break;
		}
		line[strcspn(line, "\n")] = '\0';
		if (strlen(line) == 0)
			continue;

		int num_args = parse_line(line, argv);

		if (num_args > 0)
		{
			execute_command(argv);
		}
	}
	return (0);
}


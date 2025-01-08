#include "shell.h"
#include <unistd.h>
#include <string.h>

/**
 * display_prompt - Displays the shell prompt.
 */
void display_prompt(void)
{
	const char *prompt = "simple_shell$ ";
	if (write(STDOUT_FILENO, prompt, strlen(prompt)) == -1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}
}

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
void parse_command(char *line, char **argv)
{
	line[strcspn(line, "\n")] = '\0';
	argv[0] = line;
	argv[1] = NULL;
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

/**
 * main_loop - The main loop of the shell.
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

		if (nread == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		if (nread > 1)
		{
			parse_command(line, argv);
			execute_command(argv);
		}
	}

	free(line);
}

/**
 * main - Entry point for the shell program.
 *
 * Return: Always 0.
 */
int main(void)
{
	main_loop();
	return 0;
}

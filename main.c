#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * main - Entry point of the shell program.
 *
 * Return: Always 0 (Success).
 */
int main(void)
{
	char *line;
	char **argv;
	int status;

	while (1)
	{
		display_prompt();

		line = read_command();
		if (line == NULL)
		{
			free(line);
			break;
		}

		if (strlen(line) == 0)
		{
			free(line);
			continue;
		}

		argv = split_command(line);

		status = execute_command(argv);

		if (status == 0)
		{
			fprintf(stderr, "%s: No such file or directory\n", argv[0]);
		}

		free(argv);
		free(line);
	}

	return (0);
}

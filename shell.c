#include "shell.h"
#include <stdio.h>

#define PROMPT "ツ"

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
			printf("\n");
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
			fprintf(stderr, "%s: 1: %s: not found\n", argv[0], argv[0]);
		}

		free(argv);
		free(line);
	}

	printf("\n");

	return (0);
}

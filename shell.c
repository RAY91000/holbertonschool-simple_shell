#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
		if (line == NULL)  /* This handles EOF (Ctrl+D) */
		{
			printf("\n");
			break;  /* Exit the shell when EOF is received */
		}

		if (strlen(line) == 0)
		{
			free(line);
			continue;  /* Don't execute if the line is empty */
		}

		argv = split_command(line);

		status = execute_command(argv);

		/* Check if the command was found or not */
		if (status == 0)
		{
			fprintf(stderr, "%s: No such file or directory\n", argv[0]);
		}

		free(argv);
		free(line);
	}

	return (0);  /* The shell exits here, no prompt after exit */
}

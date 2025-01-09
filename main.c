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
		display_prompt();  /* Print prompt before reading input */

		line = read_command();
		if (line == NULL)  /* Handle EOF (Ctrl+D) */
		{
			free(line);
			break;  /* Exit the shell when EOF is received */
		}

		if (strlen(line) == 0)  /* Skip empty lines */
		{
			free(line);
			continue;
		}

		argv = split_command(line);

		status = execute_command(argv);  /* Execute the command */

		if (status == 0)  /* If execution fails, print error */
		{
			fprintf(stderr, "%s: No such file or directory\n", argv[0]);
		}

		free(argv);
		free(line);
	}

	return (0);  /* Exit cleanly, no prompt after exit */
}

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
		display_prompt();  /* Display the prompt. */

		line = read_command();  /* Read the user's input. */
		if (line == NULL)  /* Handle EOF (Ctrl+D). */
		{
			break;  /* Exit the loop if Ctrl+D is pressed. */
		}

		if (strlen(line) == 0)  /* Handle empty input. */
		{
			free(line);
			continue;  /* Skip to the next iteration if input is empty. */
		}

		argv = split_command(line);  /* Split the command into arguments. */

		status = execute_command(argv);  /* Execute the command. */

		if (status == 0)  /* Command not found. */
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
		}

		free(argv);  /* Free memory. */
		free(line);  /* Free memory. */
	}

	return (0);  /* No need for extra newline here. */
}

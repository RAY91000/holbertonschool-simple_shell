#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * display_prompt - Function to display custom prompt.
 */
void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		printf("$ ");
		fflush(stdout);
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * read_command - Function to read the input command from the user.
 *
 * Return: A string containing the user's command input.
 */
char *read_command(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	nread = getline(&line, &len, stdin);
	if (nread == -1) /* Handle EOF (Ctrl+D) */
	{
		if (isatty(STDIN_FILENO)) /* Print newline only in interactive mode */
			write(STDOUT_FILENO, "\n", 1);
		free(line);
		return (NULL);
	}

	/* Remove newline character at the end */
	line[strcspn(line, "\n")] = '\0';

	return (line);
}

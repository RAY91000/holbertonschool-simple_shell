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
	size_t i;

	nread = getline(&line, &len, stdin);
	if (nread == -1)
	{
		free(line);  /* Handle EOF (Ctrl+D) */
		return (NULL);
	}

	/* Remove unwanted characters (like escape sequences) */
	for (i = 0; i < strlen(line); i++)
	{
		if (line[i] == 27 || line[i] < 32)
		{
			line[i] = ' ';
		}
	}

	/* Remove newline character at the end */
	line[strcspn(line, "\n")] = '\0';

	return (line);
}

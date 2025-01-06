#include "shell.h"

/**
 * read_command - Function to read the input command from the user.
 *
 * Return: A string containing the user's command input.
 */
char *read_command(void)
{
	char *line = NULL;
	size_t len = 0;

	if (getline(&line, &len, stdin) == -1)
	{
		free(line);
		return (NULL);
	}

	line[strcspn(line, "\n")] = '\0';
	printf("\n");
	return (line);
}

#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * handle_exit - Handles the exit command.
 * @argv: Array of arguments.
 */
void handle_exit(char **argv)
{
	if (argv[0] && strcmp(argv[0], "exit") == 0)
		exit(0);
}

/**
 * handle_echo - Handles the echo command.
 * @argv: Array of arguments.
 */
void handle_echo(char **argv)
{
	int i = 1;

	if (argv[0] && strcmp(argv[0], "echo") == 0)
	{
		while (argv[i] != NULL)
		{
			printf("%s", argv[i]);
			if (argv[i + 1] != NULL)
				printf(" ");
			i++;
		}
		printf("\n");
		exit(0);
	}
}

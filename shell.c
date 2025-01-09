#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char **argv;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			display_prompt();

		nread = read_command(&line, &len);
		if (nread == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		if (nread > 1)
		{
			argv = parse_command(line);
			execute_command(argv);
			free(argv);
		}
	}

	free(line);
	return (0);
}

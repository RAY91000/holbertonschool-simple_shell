#include "shell.h"

/**
 * main_loop - The main loop of the shell.
 */
void main_loop(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char *argv[2];

	while (1)
	{
		display_prompt();
		nread = read_command(&line, &len);

		if (nread == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		if (nread > 1)
		{
			parse_command(line, argv);
			execute_command(argv);
		}
	}

	free(line);
}

/**
 * main - Entry point for the shell program.
 */
int main(void)
{
	main_loop();
	return (0);
}

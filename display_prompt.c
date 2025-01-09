#include "shell.h"
#include <unistd.h>
#include <string.h>

/**
 * display_prompt - Displays the shell prompt.
 */
void display_prompt(void)
{
	const char *prompt = "simple_shell$ ";

	if (write(STDOUT_FILENO, prompt, strlen(prompt)) == -1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}
}

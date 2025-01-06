#include "shell.h"

/**
 * display_prompt - Function to display custom prompt.
 */
void display_prompt(void)
{
	printf("%s", PROMPT);
	fflush(stdout);
}

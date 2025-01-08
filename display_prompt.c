#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * display_prompt - Function to display custom prompt.
 */
void display_prompt(void)
{
	write(STDOUT_FILENO, PROMPT, strlen(PROMPT));
}

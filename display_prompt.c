#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include "shell.h"

#define PROMPT "ツ"

/**
 * prompt - Function to print a custom prompt
 * if input is from a terminal.
 */

void display_prompt(void)
{

	struct stat buf;

	fstat(STDIN_FILENO, &buf);
	if (S_ISCHR(buf.st_mode))
{
	printf("%s", PROMPT);
	fflush(stdout);
}
}

/**
 * main - Entry point for the program
 *
 * Return: Always 0 (Success)
 */

int main(void)
{

	display_prompt();

	return (0);
}

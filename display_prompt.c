#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include "shell.h"

#define PROMPT "ツ"

extern char **environ;
/**
 * display_prompt - Function to display custom prompt
 */
void display_prompt(void)
{
	printf("%s", PROMPT);
	fflush(stdout);
}

/**
 * main - Entry point for the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *line = NULL;
	char *argv[64];
	size_t len = 0;
	ssize_t nread;
	int status;

	while (1)
	{
		display_prompt();

		nread = getline(&line, &len, stdin);

		if (nread == -1)
		{
			free(line);
			printf("\n");
			break;
		}

		line[strcspn(line, "\n")] = '\0';

		if (strlen(line) == 0)
			continue;

		argv[0] = strtok(line, " ");
		int i = 1;
		while ((argv[i] = strtok(NULL, " ")) != NULL)
		{
			i++;
		}
		argv[i] = NULL;

		pid_t pid = fork();

		if (pid == 0)
		{
			if (execve(argv[0], argv, environ) == -1)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
		}
		else if (pid > 0)
		{
			wait(&status);
		}
		else
		{
			perror("fork failed");
			exit(EXIT_FAILURE);
		}
	}

	return (0);
}

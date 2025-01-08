#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PROMPT "simple_shell$ "

extern char **environ;

/**
 * main - UNIX command line interpreter.
 *
 * Description: Displays a prompt and waits for user to type a command.
 *              Handles commands without arguments and basic error handling.
 *
 * Return: Always 0 (Success).
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char *argv[2];
	pid_t pid;
	int status;

	while (1)
	{

		printf("%s", PROMPT);


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

		argv[0] = line;
		argv[1] = NULL;

		pid = fork();
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
			perror("Error: fork failed");
			free(line);
			exit(EXIT_FAILURE);
		}
	}

	return (0);
}

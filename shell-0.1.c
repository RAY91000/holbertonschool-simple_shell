#include "shell.h"

extern char **environ;

int main(void)
{
	char *line = NULL;
	char *argv[2];
	size_t len = 0;
	ssize_t nread;

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

		argv[0] = line;
		argv[1] = NULL;

		if (fork() == 0)
		{
			if (execve(argv[0], argv, environ) == -1)
				perror("Error");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}
	}
	return (0);
}

void display_prompt(void)
{
	printf("($) ");
	fflush(stdout);
}

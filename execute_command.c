#include "shell.h"
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

/**
 * execute_command - Function to fork and execute a command using execve.
 * @argv: Array of arguments to pass to execve.
 *
 * Return: 1 if the command executed successfully, otherwise 0.
 */
int execute_command(char **argv)
{
	pid_t pid = fork();
	int status;
	int i;
	struct stat buf;

	if (pid == 0)
	{
		if (strcmp(argv[0], "exit") == 0)
		{
			exit(0); }
		else if (strcmp(argv[0], "echo") == 0)
		{
			for (i = 1; argv[i] != NULL; i++)
			{
				printf("%s ", argv[i]);
			}
			printf("\n");
			exit(0); }
		else if (argv[0][0] == '/')
		{
			if (stat(argv[0], &buf) == 0 && (buf.st_mode & S_IXUSR))
			{

				execve(argv[0], argv, environ); }
			else
			{
				perror(argv[0]);
				exit(EXIT_FAILURE); }}
		else
		{
			if (command_exists(argv[0]))
			{
				execve(argv[0], argv, environ); }
			else
			{
				perror(argv[0]);
				exit(EXIT_FAILURE); }}}
	else if (pid > 0)
	{
		wait(&status); }
	else
	{
		perror("fork failed");
		return (0); }
	return (1); }

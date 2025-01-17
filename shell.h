#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* Global variable for environment */
extern char **environ;

/* Define the prompt */
#define PROMPT "$ "

/* Function prototypes */
void display_prompt(void);
char *read_command(void);
char **split_command(char *command);
int execute_command(char **argv);
int command_exists(char *cmd);
void handle_exit(char **argv);
void handle_echo(char **argv);
int handle_execve(char **argv);

#endif /* MAIN_H */


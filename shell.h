#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.>

extern char **environ;
/* Prototypes */
void display_prompt(void);
char *read_command(void);
char **split_command(char *command);
void execute_command(char **argv);
int parse_line(char *line, char **argv);
int command_exists(char *cmd);

#endif /* MAIN_H */

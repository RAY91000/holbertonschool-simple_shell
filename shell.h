#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

/* Function prototypes */
void display_prompt(void);
ssize_t read_command(char **line, size_t *len);
char **parse_command(char *line);
void execute_command(char **argv);

#endif /* SHELL_H */

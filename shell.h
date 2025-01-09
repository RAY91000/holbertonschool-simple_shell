#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

extern char **environ;

/* Function prototypes */
void display_prompt(void);
ssize_t read_command(char **line, size_t *len);
void parse_command(char *line, char **argv);
void execute_command(char **argv);
void main_loop(void);

#endif /* SHELL_H */

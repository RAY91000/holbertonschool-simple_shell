#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* Define the prompt */
#define PROMPT "ツ"

/* Prototypes */
void display_prompt(void);
char *read_command(void);
char **split_command(char *command);
int execute_command(char **argv);

#endif /* MAIN_H */


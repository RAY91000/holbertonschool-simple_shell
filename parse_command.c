#include "shell.h"

/**
 * parse_command - Parse the command line into arguments.
 * @line: The command line to parse.
 * @argv: Array to store the arguments.
 */
void parse_command(char *line, char **argv)
{
	line[strcspn(line, "\n")] = '\0';
	argv[0] = line;
	argv[1] = NULL;
}

/**
 * read_command - Reads a command line from standard input.
 * @line: Pointer to the buffer where the command will be stored.
 * @len: Pointer to the size of the buffer.
 *
 * Return: Number of characters read, or -1 if an error or EOF is encountered.
 */
ssize_t read_command(char **line, size_t *len)
{
    return getline(line, len, stdin);
}

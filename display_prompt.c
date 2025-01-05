#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <shell.h>

#define PROMPT "ツ"

/**
 *
 *
 */

void prompt(int fd, struct stat buf)
{

	fstat(fd, &buf);

	if (S_ISCHR(buf.st_mode)) 
{
	printf("%s", PROMPT);
	fflush(stdout);
}
}

/**
 *
 *
 */

int main(void)
{
	struct stat buf;

	prompt(STDIN_FILENO, buf);

	return (0);
}

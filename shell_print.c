#include "simple_shell.h"

void shell_print(const char *string)
{
	write(STDOUT_FILENO, string, strlen(string));
}


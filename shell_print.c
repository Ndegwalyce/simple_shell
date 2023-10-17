#include "simple_shell.h"

/**
 * shell_print - Prints a string to standard output (STDOUT).
 *
 * @string: The string to be printed.
 *
 *
 * Return: None.
 */

void shell_print(const char *string)
{
	write(STDOUT_FILENO, string, strlen(string));
}


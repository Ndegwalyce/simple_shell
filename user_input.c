#include "simple_shell.h"

/**
 * read_input - Read user input from standard input (stdin).
 *
 * @command: The buffer to store the user input.
 * @size: The maximum size of the input buffer.
 *
 * Return: None.
 */
void read_input(char *command, size_t size)
{
if (fgets(command, size, stdin) == NULL)
{
if (feof(stdin))
{
printf("\n");
exit(EXIT_SUCCESS);
}
else
{
perror("fgets");
exit(EXIT_FAILURE);
}
}
command[strcspn(command, "\n")] = '\0';
}

#include "simple_shell.h"

/**
 * main - Entry point for a simple shell program.
 *
 * Return: Always returns 0 to indicate successful execution.
 */

int main(void)
{
	char command[150];

	while (true)
	{
		prompt_display();
		read_input(command, sizeof(command));
		execute_command(command);
	}
	return (0);
}

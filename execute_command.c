#include "simple_shell.h"

/**
 * execute_command - Execute a shell command in a child process.
 *
 * @command: The command to be executed.
 *
 * Return: None.
 */
void execute_command(const char *command)
{
pid_t child_pid = fork();
if (child_pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (child_pid == 0)
{
execlp(command, command, (char *)NULL);
perror("execlp");
exit(EXIT_FAILURE);
}
else
{
wait(NULL);
}
}

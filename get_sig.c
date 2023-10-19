#include "main.h"

/**
 * custom_handle_sigint - Handle the Ctrl+C call in the prompt
 * @signal: Signal handler
 */

void custom_handle_sigint(int signal)
{
    (void)signal;
    write(STDOUT_FILENO, "\n^-^ ", 5);
}


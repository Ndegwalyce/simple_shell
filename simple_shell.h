#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>

void shell_print(const char *message);
void prompt_display(void);
void execute_command(const char *command);
void read_input(char *command, size_t size);

#endif /* SHELL_H */

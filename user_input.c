#include "simple_shell.h"
void read_input(char *command, size_t size) {
    if (fgets(command, size, stdin) == NULL) {
        if (feof(stdin)) {
            shell_print("\n");
            exit(EXIT_SUCCESS);
        } else {
            perror("fgets");
            exit(EXIT_FAILURE);
        }
    }
   
    command[strcspn(command, "\n")] = '\0';
}

#include "main.h"

/**
 * custom_read_line - reads the input string.
 *
 * @eof_indicator: return value of getline function
 * Return: input string
 */
char *custom_read_line(int *eof_indicator)
{
    char *input = NULL;
    size_t buffer_size = 0;

    *eof_indicator = getline(&input, &buffer_size, stdin);

    return input;
}


#include "main.h"

/**
 * assign_buffer - assign the buffer to the line pointer
 * @lineptr: Buffer that stores the input string
 * @line_buffer: String that is being assigned to line
 * @line_size: Size of the line buffer
 * @buffer_size: Size of the string buffer
 */
void assign_buffer(char **lineptr, size_t *line_size, char *line_buffer, size_t buffer_size)
{
    if (*lineptr == NULL)
    {
        if (buffer_size > CUSTOM_BUFSIZE)
            *line_size = buffer_size;
        else
            *line_size = CUSTOM_BUFSIZE;
        *lineptr = line_buffer;
    }
    else if (*line_size < buffer_size)
    {
        if (buffer_size > CUSTOM_BUFSIZE)
            *line_size = buffer_size;
        else
            *line_size = CUSTOM_BUFSIZE;
        *lineptr = line_buffer;
    }
    else
    {
        _strcpy(*lineptr, line_buffer);
        free(line_buffer);
    }
}

/**
 * custom_get_line - Read input from a stream
 * @lineptr: Buffer that stores the input
 * @line_size: Size of lineptr
 * @stream: Stream to read from
 * Return: The number of bytes
 */
ssize_t custom_get_line(char **lineptr, size_t *line_size, FILE *stream)
{
    int i;
    static ssize_t input = 0;
    ssize_t retval;
    char *line_buffer;
    char character = 'z';

    if (input == 0)
        fflush(stream);
    else
        return -1;
    input = 0;

    line_buffer = malloc(sizeof(char) * CUSTOM_BUFSIZE);
    if (line_buffer == 0)
        return -1;

    while (character != '\n')
    {
        i = read(STDIN_FILENO, &character, 1);
        if (i == -1 || (i == 0 && input == 0))
        {
            free(line_buffer);
            return -1;
        }
        if (i == 0 && input != 0)
        {
            input++;
            break;
        }
        if (input >= CUSTOM_BUFSIZE)
            line_buffer = _realloc(line_buffer, input, input + 1);
        line_buffer[input] = character;
        input++;
    }

    line_buffer[input] = '\0';
    assign_buffer(lineptr, line_size, line_buffer, input);
    retval = input;
    if (i != 0)
        input = 0;
    return retval;
}


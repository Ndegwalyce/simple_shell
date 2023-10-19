#include "main.h"

/**
 * custom_remove_comments - deletes comments from the input
 *
 * @input_string: input string
 * Return: input without comments
 */
char *custom_remove_comments(char *input_string)
{
    int i, up_to;

    up_to = 0;
    for (i = 0; input_string[i]; i++)
    {
        if (input_string[i] == '#')
        {
            if (i == 0)
            {
                free(input_string);
                return NULL;
            }

            if (input_string[i - 1] == ' ' || input_string[i - 1] == '\t' || input_string[i - 1] == ';')
                up_to = i;
        }
    }

    if (up_to != 0)
    {
        input_string = _realloc(input_string, i, up_to + 1);
        input_string[up_to] = '\0';
    }

    return input_string;
}

/**
 * custom_shell_loop - Loop of the custom shell
 * @shell_data: data relevant (arguments, input, and more)
 *
 * Return: no return.
 */
void custom_shell_loop(data_shell *shell_data)
{
    int continue_loop, end_of_file;
    char *input_string;

    continue_loop = 1;
    while (continue_loop == 1)
    {
        write(STDIN_FILENO, "^-^ ", 4);
        input_string = custom_read_line(&end_of_file);
        if (end_of_file != -1)
        {
            input_string = custom_remove_comments(input_string);
            if (input_string == NULL)
                continue;

            if (check_syntax_error(shell_data, input_string) == 1)
            {
                shell_data->status = 2;
                free(input_string);
                continue;
            }
            input_string = rep_var(input_string, shell_data);
            continue_loop = split_commands(shell_data, input_string);
            shell_data->counter += 1;
            free(input_string);
        }
        else
        {
            continue_loop = 0;
            free(input_string);
        }
    }
}

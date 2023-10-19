#include "main.h"

/**
 * custom_reverse_string - reverses a string.
 * @string: input string.
 * Return: no return.
 */
void custom_reverse_string(char *string)
{
    int length = 0, i, j;
    char *str, temp;

    while (length >= 0)
    {
        if (string[length] == '\0')
            break;
        length++;
    }
    str = string;

    for (i = 0; i < (length - 1); i++)
    {
        for (j = i + 1; j > 0; j--)
        {
            temp = *(str + j);
            *(str + j) = *(str + (j - 1));
            *(str + (j - 1)) = temp;
        }
    }
}


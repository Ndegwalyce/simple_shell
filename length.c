#include "main.h"

/**
 * custom_get_length - Get the length of a number.
 * @n: Integer number.
 * Return: Length of the number.
 */
int custom_get_length(int n)
{
    unsigned int n_abs;
    int length = 1;

    if (n < 0)
    {
        length++;
        n_abs = (unsigned int)(n * -1);
    }
    else
    {
        n_abs = (unsigned int)n;
    }

    while (n_abs > 9)
    {
        length++;
        n_abs /= 10;
    }

    return length;
}

/**
 * custom_itoa - Convert an integer to a string.
 * @n: Integer number.
 * Return: String.
 */
char *custom_itoa(int n)
{
    unsigned int n_abs;
    int length = custom_get_length(n);
    char *result;

    result = malloc(sizeof(char) * (length + 1));
    if (result == NULL)
        return NULL;

    result[length] = '\0';

    if (n < 0)
    {
        n_abs = (unsigned int)(n * -1);
        result[0] = '-';
    }
    else
    {
        n_abs = (unsigned int)n;
    }

    length--;
    do {
        result[length] = (char)((n_abs % 10) + '0');
        n_abs /= 10;
        length--;
    } while (n_abs > 0);

    return result;
}

/**
 * custom_atoi - Convert a string to an integer.
 * @s: Input string.
 * Return: Integer.
 */
int custom_atoi(char *s)
{
    unsigned int index = 0, str_size = 0, result = 0, positive = 1, multiplier = 1, i;

    while (s[index] != '\0')
    {
        if (str_size > 0 && (s[index] < '0' || s[index] > '9'))
            break;

        if (s[index] == '-')
            positive *= -1;

        if (s[index] >= '0' && s[index] <= '9')
        {
            if (str_size > 0)
                multiplier *= 10;
            str_size++;
        }
        index++;
    }

    for (i = index - str_size; i < index; i++)
    {
        result = result + ((s[i] - '0') * multiplier);
        multiplier /= 10;
    }

    return result * positive;
}


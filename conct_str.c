#include "main.h"

/**
 * custom_concatenate_strings - concatenate two strings
 * @destination: char pointer the destination of the copied string
 * @source: const char pointer the source string
 * Return: the destination string
 */
char *custom_concatenate_strings(char *destination, const char *source)
{
    int i;
    int j;

    for (i = 0; destination[i] != '\0'; i++)
        ;

    for (j = 0; source[j] != '\0'; j++)
    {
        destination[i] = source[j];
        i++;
    }

    destination[i] = '\0';
    return destination;
}

/**
 * custom_copy_string - Copies the string pointed to by source.
 * @destination: Type char pointer the destination of the copied string
 * @source: Type char pointer the source string
 * Return: the destination string.
 */
char *custom_copy_string(char *destination, char *source)
{
    size_t index;

    for (index = 0; source[index] != '\0'; index++)
    {
        destination[index] = source[index];
    }
    destination[index] = '\0';

    return destination;
}

/**
 * custom_compare_strings - Function that compares two strings.
 * @string1: type string compared
 * @string2: type string compared
 * Return: 0 if equal, 1 if string1 > string2, -1 if string1 < string2
 */
int custom_compare_strings(char *string1, char *string2)
{
    int index;

    for (index = 0; string1[index] == string2[index] && string1[index]; index++)
        ;

    if (string1[index] > string2[index])
        return 1;
    if (string1[index] < string2[index])
        return -1;
    return 0;
}

/**
 * custom_find_character - locates a character in a string,
 * @string: string.
 * @character: character.
 * Return: the pointer to the first occurrence of the character.
 */
char *custom_find_character(char *string, char character)
{
    unsigned int index = 0;

    for (; *(string + index) != '\0'; index++)
        if (*(string + index) == character)
            return (string + index);
    if (*(string + index) == character)
        return (string + index);
    return ('\0');
}

/**
 * custom_length_of_prefix - gets the length of a prefix substring.
 * @string: initial segment.
 * @accepted_bytes: accepted bytes.
 * Return: the number of accepted bytes.
 */
int custom_length_of_prefix(char *string, char *accepted_bytes)
{
    int i, j, bool;

    for (i = 0; *(string + i) != '\0'; i++)
    {
        bool = 1;
        for (j = 0; *(accepted_bytes + j) != '\0'; j++)
        {
            if (*(string + i) == *(accepted_bytes + j))
            {
                bool = 0;
                break;
            }
        }
        if (bool == 1)
            break;
    }
    return i;
}


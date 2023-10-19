#include "main.h"

/**
 * custom_add_variable_node - adds a variable at the end
 * of a variable list.
 * @head: head of the linked list.
 * @var_length: length of the variable.
 * @value: value of the variable.
 * @value_length: length of the value.
 * Return: address of the head.
 */
r_var *custom_add_variable_no(r_var **head, int var_length, char *value, int value_length)
{
    r_var *new_node, *temp;

    new_node = malloc(sizeof(r_var));
    if (new_node == NULL)
        return NULL;

    new_node->var_length = var_length;
    new_node->value = value;
    new_node->value_length = value_length;

    new_node->next = NULL;
    temp = *head;

    if (temp == NULL)
    {
        *head = new_node;
    }
    else
    {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
    }

    return *head;
}

/**
 * custom_free_variable_list - frees a variable list
 * @head: head of the linked list.
 * Return: no return.
 */
void custom_free_variable_list(r_var **head)
{
    r_var *temp;
    r_var *current;

    if (head != NULL)
    {
        current = *head;
        while ((temp = current) != NULL)
        {
            current = current->next;
            free(temp);
        }
        *head = NULL;
    }
}

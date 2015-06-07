#include <stdio.h>
#include "libasm.h"

/*
 * This function iterates over each element
 * of a given list.
 */
void print_list(node_t *head)
{
    if (head == 0)
    {
        return ;
    }
    node_t  *current = head;
    while (current != NULL)
    {
        printf("%s", (char *)current->value);
        current = current->next;
    }
    return ;
}


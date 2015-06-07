#include "libasm.h"
#include <stdlib.h>

/*
 * This function adds an item at the end
 * of the list.
 * The first step is to go at the end of the list.
 * Then we can add our new value.
 * The last step is setting our next next to NULL
 */
void push_last(node_t *head, void *new_value)
{
    node_t  *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = (node_t *)malloc(sizeof(node_t));
    current->next->value = new_value;
    current->next->next = NULL;
    return ;
}


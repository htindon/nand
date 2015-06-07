#include "libasm.h"

node_t *apply_to_list(node_t *head, char *(*f)(char *))
{
    node_t  *current = head;

    while (current)
    {
        current->value = (*f)(current->value);
        current = current->next;
    }
    return (head);
}


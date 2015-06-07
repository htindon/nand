#include "libasm.h"
#include <stdlib.h>

node_t *init_list(void *first_value)
{
    node_t *head = NULL;
    head = (node_t *)malloc(sizeof(node_t));
    if (!first_value)
    {
        return (0);
    }
    head->value = first_value;
    head->next = NULL;
    return (head);
}

#include <stdlib.h>
#include "libasm.h"

node_t    *parse_symbols(node_t *list)
{
    if (list == 0)
    {
        return (0);
    }
    char *line;
    node_t *current = list;
    node_t *head = NULL;

    line = (char *)malloc(sizeof(char) * 1024);
    head = (node_t *)malloc(sizeof(node_t));
    head = init_list(line);
    while (current != NULL)
    {
        line = (char *)current->value;
        if (find_char(line, '('))
        {
            push_last(head, line);
        }
        current = current->next;
    }
    free(line);
    return (head);
}

#include <stdio.h>
#include <stdlib.h>
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

/*
 * This functions takes a file and extracts
 * its contents line by line. It feeds
 * each line to a linked list that it finally
 * returns.
 */
node_t *file_to_list(char *filename)
{
    FILE    *fd;
    char    *line;
    node_t  *head;

    /* Initializing head and line */
    head = (node_t *)malloc(sizeof(node_t));
    line = (char *)malloc(sizeof(char) * 1024);

    /* Opening a file and reading a line */
    fd = fopen(filename, "r");
    line = get_line(fd);

    /* Initializing linked list with the content of line */
    head = init_list(line);

    /* Getting a new line and pushing it to the list */
    while (42)
    {
        line = get_line(fd);
        if (!line)
        {
            break ;
        }
        push_last(head, line);
    }

    free(line);
    return (head);
}

int main(int argc, char **argv)
{
    node_t *data;
    node_t *symbols;

    data = (node_t *)malloc(sizeof(node_t));
    symbols = (node_t *)malloc(sizeof(node_t));
    /* Checking number of arguments and both mallocs */
    if (argc != 2 || !data || !symbols)
    {
        return (1);
    }
    data = file_to_list(argv[1]);
    apply_to_list(data, trim);
    print_list(data);
    symbols = parse_symbols(data);
    print_list(symbols);
    free(data);
    return (0);
}

#include "libasm.h"
#include <stdlib.h>

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


#include <stdio.h>
#include <stdlib.h>
#include "libasm.h"

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

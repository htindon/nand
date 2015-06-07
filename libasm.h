#ifndef LIBASM_H
# define LIBASM_H
# include <stdio.h>

typedef struct node {
    void *value;
    struct node *next;
} node_t;

int find_char(char *array, char c);
char *get_line(FILE *fd);
char *trim(char *line);
node_t *parse_symbols(node_t *list);
node_t *file_to_list(char *filename);
node_t *apply_to_list(node_t *head, char *(*f)(char *));

/* List functions */
void    push_first(node_t **head, void *new_value);
void    push_last(node_t *head, void *new_value);
void    print_list(node_t *head);
char    *pop_first(node_t **head);
char    *pop_last(node_t *head);
char    *pop_by_index(node_t **head, int n);
char    *pop_by_value(node_t **head, void *rm_value);
node_t  *init_list(void *first_value);

#endif

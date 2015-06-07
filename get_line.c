#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * The get_line function only extracts one line
 * from a given file.
 */
char *get_line(FILE *fd)
{
    char *line;
    int i = 0;

    line = (char *)malloc(sizeof(char) * 1024);
    memset(line, 0, 1024);
    while ((line[i] = fgetc(fd)) != '\n')
    {
        if (feof(fd))
        {
            return (0);
        }
        i++;
    }
    return (line);
}

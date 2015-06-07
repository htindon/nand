#include <stdlib.h>
#include <string.h>

/*
 * The trim function gets rid of all spaces
 * It also gets rid of comments in lines and
 */

char *trim(char *line)
{
    int i;
    int size;
    char *newline;

    i = 0;
    size = 0;
    newline = (char *)malloc(sizeof(char) * 1024);
    memset(newline, 0, 1024);
    while (line[i])
    {
        if (line[i] == '/' && line[i + 1] == '/')
        {
            newline[size] = '\r';
            size++;
            newline[size] = '\n';
            size++;
            break ;
        }
        else if (line[i] != ' ')
        {
            newline[size] = line[i];
            size++;
        }
        i++;
    }
    newline = (char *)realloc(newline, size + 1);
    return ((void*)newline);
} 

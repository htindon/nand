int     find_char(char *array, char c)
{
    int i;

    i = 0;
    while (array[i])
    {
        if (array[i] == c)
        {
            return (1);
        }
        i++;
    }
    return (0);
}

int ft_isalpha(char *str)
{
    while (*str)
    {
        if (*str < 'A' || *str > 'z' || (*str > 'Z' && *str < 'a'))
            return (0);
        str++;
    }
    return (1);
}
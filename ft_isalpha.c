int ft_isalpha(int c)
{
    if (c < 'A' || c > 'z' || (c > 'Z' && c < 'a'))
        return (0);
    return (1);
}
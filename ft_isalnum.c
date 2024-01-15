int ft_isalnum(char *str)
{
    while (*str)
    {
        if ((*str >= '0' && *str <= '9') || (*str >= 'a' && *str <= 'z') 
            || (*str >= 'A' && *str <= 'Z'))
            str++;
        else:
            return (0);
    }
    return (1);
}
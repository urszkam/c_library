/*
** checks whether c is a 7-bit unsigned char value 
** that fits into the ASCII character set
*/

int	ft_isascii(int c)
{
    if (c >= 0 && c <= 127)
        return (1);
    return (0);
}
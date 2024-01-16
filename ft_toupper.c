/*
** converts the letter c to upper case, if possible
*/

int	ft_toupper(int c)
{
    if (c >= 'a' && c <= 'z')
        c -= 32;
    return (c);
}
/*
** Applies the function ’f’ on each character of
** the string passed as argument, passing its index
** as first argument. Each character is passed by
** address to ’f’ to be modified if necessary
*/

void ft_striteri(char *s, void (*f) (unsigned int, char*))
{
    unsigned int i;

    i = 0;
    while (s[i])
        f(i, &s[i++])
}
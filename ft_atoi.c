/*
** converts the initial portion of the string pointed to by nptr to int
*/

#include "libft.h"
#include <stdio.h>

int ft_atoi(const char *nptr)
{
    long res;
    int sign;

    while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
        nptr++;
    sign = 1;
    if (*nptr == '+' || *nptr == '-')
    {
        if (*nptr == '-')
            sign *= -1;
        nptr++;
    }
    res = 0;
    while (*nptr && *nptr >= '0' && *nptr <= '9')
    {
        res = res * 10 + (*nptr - '0');
        nptr++;
    }
    return (res * sign);
}

// int main(int i, char **c)
// {
//     if (i == 2)
//     {
//         int result = atoi(c[1]);
//         int result2 = ft_atoi(c[1]);
//         printf("Result: %d, %d\n", result, result2);
//     }

//     return 0;
// }
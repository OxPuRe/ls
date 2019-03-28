#include <libft.h>

void                ft_memswap(void *x, void *y, size_t size)
{
    unsigned char    *a;
    unsigned char    *b;
    unsigned char    c;

    a = (unsigned char *)x;
    b = (unsigned char *)y;
    if (x < y)
    {
        while (size--)
        {
            c = *a;
            *a++ = *b;
            *b++ = c;
        }
    }
    else
    {
        while (size--)
        {
            c = a[size];
            a[size] = b[size];
            b[size] = c;
        }
    }
}
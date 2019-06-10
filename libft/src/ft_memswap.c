/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 00:50:01 by auverneu          #+#    #+#             */
/*   Updated: 2019/06/10 00:52:48 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void                ft_memswap(void *x, void *y, size_t size)
{
    unsigned char   *a;
    unsigned char   *b;
    unsigned char   c;

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

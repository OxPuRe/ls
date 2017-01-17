/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:34:26 by auverneu          #+#    #+#             */
/*   Updated: 2015/12/07 18:02:30 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*srcc;
	unsigned char	cc;

	dest = (unsigned char *)dst;
	srcc = (unsigned char *)src;
	cc = c;
	while (*srcc != cc && n > 0)
	{
		*dest = *srcc;
		dest++;
		srcc++;
		n--;
	}
	if (*srcc == cc)
	{
		*dest = *srcc;
		dest++;
		return ((void *)dest);
	}
	else
		return (NULL);
}

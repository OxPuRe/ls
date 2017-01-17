/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:12:11 by auverneu          #+#    #+#             */
/*   Updated: 2015/12/07 18:18:04 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dstc;
	const char	*srcc;

	dstc = dst;
	srcc = src;
	while (n)
	{
		*dstc = *srcc;
		dstc++;
		srcc++;
		n--;
	}
	return (dst);
}

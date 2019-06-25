/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 22:32:12 by auverneu          #+#    #+#             */
/*   Updated: 2015/12/12 22:36:34 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstmem;

	dstmem = ft_strlen(dst);
	i = 0;
	if (size <= dstmem)
		return (size + ft_strlen(src));
	while (dstmem + i < (size - 1) && src[i])
	{
		dst[i + dstmem] = src[i];
		i++;
	}
	dst[i + dstmem] = '\0';
	return (dstmem + ft_strlen(src));
}

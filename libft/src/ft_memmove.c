/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 22:07:04 by auverneu          #+#    #+#             */
/*   Updated: 2016/08/25 01:33:53 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dstmem;

	dstmem = NULL;
	dstmem = (void *)malloc(len * sizeof(char));
	if (!dstmem)
		return (NULL);
	ft_memcpy(dstmem, src, len);
	ft_memcpy(dst, dstmem, len);
	free(dstmem);
	dstmem = NULL;
	return (dst);
}

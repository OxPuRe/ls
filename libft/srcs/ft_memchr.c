/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:05:34 by auverneu          #+#    #+#             */
/*   Updated: 2015/12/07 13:08:53 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	cc;
	unsigned char	*ss;

	cc = c;
	ss = (unsigned char *)s;
	while (n != 0 && *ss != cc)
	{
		ss++;
		n--;
	}
	if (n == 0)
		return (NULL);
	else if (*ss == cc)
		return ((void *)(ss));
	else
		return (NULL);
}

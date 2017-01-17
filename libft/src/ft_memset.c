/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:44:21 by auverneu          #+#    #+#             */
/*   Updated: 2015/11/25 15:27:59 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memset(void *b, int c, size_t len)
{
	int				i;
	char			*bb;
	unsigned char	cc;

	i = 0;
	bb = b;
	cc = c;
	while (len != 0)
	{
		bb[i] = cc;
		len--;
		i++;
	}
	return (b);
}

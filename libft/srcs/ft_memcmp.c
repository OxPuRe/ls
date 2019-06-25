/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 21:32:07 by auverneu          #+#    #+#             */
/*   Updated: 2015/12/05 16:22:19 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int			i;
	const char	*ss1;
	const char	*ss2;

	i = 0;
	ss1 = s1;
	ss2 = s2;
	if (ss1[0] == '\0' && ss2[0] == '\0' && n <= 1)
		return (0);
	while (ss1[i] == ss2[i] && n != 0)
	{
		i++;
		n--;
	}
	if (n == 0)
		i--;
	return ((unsigned char)ss1[i] - (unsigned char)ss2[i]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:54:22 by auverneu          #+#    #+#             */
/*   Updated: 2015/12/05 15:58:56 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && n != 0)
	{
		i++;
		n--;
	}
	if (n == 0)
		i--;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

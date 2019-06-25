/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 21:56:28 by auverneu          #+#    #+#             */
/*   Updated: 2015/12/12 22:01:37 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countwords(char const *s, char c)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (s[0] == '\0')
		return (0);
	if (s[0] != c)
		i++;
	while (s[j])
	{
		while (s[j] != c && s[j])
		{
			if (j > 0 && s[j - 1] == c)
				i++;
			j++;
		}
		while (s[j] == c)
			j++;
	}
	return (i);
}

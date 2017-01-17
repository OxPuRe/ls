/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:37:55 by auverneu          #+#    #+#             */
/*   Updated: 2015/12/15 21:56:06 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	while (s1[i] != '\0' && i < n)
	{
		while (s1[i + j] == s2[j] && (i + j) < n)
		{
			j++;
			if (s2[j] == '\0')
				return ((char *)&s1[i]);
		}
		j = 0;
		i++;
	}
	return (NULL);
}

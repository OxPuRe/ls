/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 01:29:55 by auverneu          #+#    #+#             */
/*   Updated: 2015/12/09 01:43:16 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*d;

	i = 0;
	d = NULL;
	d = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (d == NULL)
		return (NULL);
	while (*s1)
	{
		*d = *s1;
		d++;
		i++;
		s1++;
	}
	while (*s2)
	{
		*d = *s2;
		d++;
		i++;
		s2++;
	}
	*d = '\0';
	return (d - i);
}

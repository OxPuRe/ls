/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasestr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 01:52:57 by auverneu          #+#    #+#             */
/*   Updated: 2015/12/15 21:57:57 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_s1(const char *s1, char b, size_t i, size_t j)
{
	if (s1[i + j] >= 65 && s1[i + j] <= 90)
		b = s1[i + j] + 32;
	else if (s1[i + j] >= 97 && s1[i + j] <= 122)
		b = s1[i + j] - 32;
	return (b);
}

static char	ft_s2(const char *s2, char l, size_t j)
{
	if (s2[j] >= 65 && s2[j] <= 90)
		l = s2[j] + 32;
	else if (s2[j] >= 97 && s2[j] <= 122)
		l = s2[j] - 32;
	return (l);
}

char		*ft_strcasestr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	b;
	char	l;

	i = 0;
	j = 0;
	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	while (s1[i++])
	{
		b = ft_s1(s1, b, i, j);
		if (i == 0)
			l = ft_s2(s2, l, j);
		while ((s1[i + j] == s2[j]) || (s1[i + j] == l) ||
				(b == s2[j]) || (b == l))
		{
			j++;
			if (s2[j] == '\0')
				return ((char *)&s1[i]);
			l = ft_s2(s2, l, j);
		}
		j = 0;
	}
	return (NULL);
}

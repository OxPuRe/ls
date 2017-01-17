/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 22:21:26 by auverneu          #+#    #+#             */
/*   Updated: 2015/12/12 22:52:11 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_newsub(char const *s, char c, size_t *pos)
{
	char		*sub;
	size_t		start;
	size_t		len;
	size_t		pc;

	start = 0;
	pc = *pos;
	while (s[pc] == c && s[pc])
		pc++;
	start = pc;
	while (s[pc] != c && s[pc])
		pc++;
	len = pc - start;
	*pos = pc;
	sub = ft_strsub(s, start, len);
	return (sub);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tab;
	size_t		count;
	size_t		i;
	size_t		pos;

	pos = 0;
	count = ft_countwords(s, c);
	tab = (char **)ft_memalloc(sizeof(char *) * (count + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		tab[i] = ft_newsub(s, c, &pos);
		i++;
	}
	return (tab);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 00:02:41 by auverneu          #+#    #+#             */
/*   Updated: 2015/12/09 19:18:33 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*d;
	int		i;

	i = 0;
	d = NULL;
	d = ft_strnew(ft_strlen(s));
	if (d == NULL)
		return (NULL);
	while (*s)
	{
		*d = f(*s);
		d++;
		s++;
		i++;
	}
	return (d - i);
}

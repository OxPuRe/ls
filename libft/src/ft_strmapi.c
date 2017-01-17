/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 01:04:37 by auverneu          #+#    #+#             */
/*   Updated: 2015/12/09 16:16:39 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		*d = f(i, *s);
		d++;
		s++;
		i++;
	}
	return (d - i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 00:14:30 by auverneu          #+#    #+#             */
/*   Updated: 2015/12/05 22:10:40 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	cc;

	cc = c;
	while (*s != '\0')
		s++;
	if (c == '\0')
		return ((char *)s);
	s--;
	while (*s != cc && *s != '\0')
		s--;
	if (*s == cc)
		return ((char *)s);
	else
		return (NULL);
}

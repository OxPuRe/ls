/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 23:56:25 by auverneu          #+#    #+#             */
/*   Updated: 2015/11/28 00:07:38 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strchr(const char *s, int c)
{
	char	cc;

	cc = c;
	while (*s != cc && *s != '\0')
		s++;
	if (*s == cc)
		return ((char *)s);
	else
		return (NULL);
}

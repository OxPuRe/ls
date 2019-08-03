/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 23:56:25 by auverneu          #+#    #+#             */
/*   Updated: 2019/08/03 05:28:54 by auverneu         ###   ########.fr       */
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

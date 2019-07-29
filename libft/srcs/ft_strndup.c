/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 23:22:05 by thplessi          #+#    #+#             */
/*   Updated: 2019/07/29 02:06:14 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** man 3 strndup
*/

char		*ft_strndup(const char *s1, size_t n)
{
	char	*s2;
	size_t	len;

	len = ft_strnlen(s1, n);
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (s2)
	{
		ft_strncpy(s2, s1, len);
		s2[len] = '\0';
	}
	return (s2);
}

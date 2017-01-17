/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 01:18:41 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/12 20:01:07 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*d;

	i = 0;
	d = NULL;
	d = ft_strnew(len);
	if (d == NULL)
		return (NULL);
	while (len)
	{
		d[i] = s[start];
		i++;
		start++;
		len--;
	}
	d[i] = '\0';
	return (d);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcstrlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 00:22:23 by auverneu          #+#    #+#             */
/*   Updated: 2016/08/25 00:49:54 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t		ft_wcstrlen(wchar_t *w)
{
	size_t		len;
	size_t		tmp;

	len = 0;
	tmp = 0;
	while (*w)
	{
		tmp = ft_wclen(*w);
		len += ((ssize_t)tmp < 0) ? 0 : tmp;
		w++;
	}
	return (len);
}

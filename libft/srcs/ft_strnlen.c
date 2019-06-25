/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 23:06:32 by auverneu          #+#    #+#             */
/*   Updated: 2019/06/18 23:06:38 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
** man 3 strnlen
*/

size_t		ft_strnlen(const char *s, size_t maxlen)
{
	size_t	ret;

	ret = 0;
	while (s[ret] && ret < maxlen)
		ret++;
	return (ret);
}

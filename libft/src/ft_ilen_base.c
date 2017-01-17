/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ilen_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:54:02 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/02 00:01:54 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** This function return the length of a given number in the given base.
** Return:	The length of the number.
*/

size_t		ft_ilen_base(unsigned int x, unsigned int base)
{
	size_t	ret;

	ret = 0;
	if (base < 2 || base > 16)
		return (0);
	if (x == 0)
		return (1);
	while (x != 0)
	{
		x /= base;
		ret++;
	}
	return (ret);
}

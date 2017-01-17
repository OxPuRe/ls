/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llonglen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 22:03:49 by auverneu          #+#    #+#             */
/*   Updated: 2016/08/26 01:40:12 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_llonglen(long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n == LLONG_MIN)
		return (20);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

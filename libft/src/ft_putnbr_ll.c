/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 21:58:22 by auverneu          #+#    #+#             */
/*   Updated: 2016/05/12 13:22:21 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>

void	ft_putnbr_ll(long long n)
{
	long long	i;

	i = n;
	if (n == LONG_MIN)
	{
		ft_putstr("9223372036854775808");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		i = -n;
	}
	if (i > 9)
	{
		ft_putnbr_ll(i / 10);
		ft_putnbr_ll(i % 10);
	}
	else
		ft_putchar(i + 48);
}

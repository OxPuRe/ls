/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:54:53 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/12 19:57:16 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_atoi(char *str)
{
	int nb;
	int	i;
	int	sign;

	nb = 0;
	i = 0;
	sign = 1;
	while (str[i] == '\n' || str[i] == ' ' || str[i] == '\r' ||
			str[i] == '\f' || str[i] == '\v' || str[i] == '\t')
		i++;
	while (str[i] < '0' && str[i] > '9')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb * sign);
}

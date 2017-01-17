/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:54:53 by auverneu          #+#    #+#             */
/*   Updated: 2016/10/28 14:21:56 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

unsigned int		ft_atoi_base(char *str, int base)
{
	unsigned int	nb;
	unsigned int	ret;

	ret = 0;
	if (base <= 1 || base > 16)
		return (0);
	while (*str == '\n' || *str == ' ' || *str == '\r' ||
			*str == '\f' || *str == '\v' || *str == '\t')
		str++;
	while ((*str >= '0' && *str <= '9') || (*str >= 'a' && *str <= 'f')
		|| (*str >= 'A' && *str <= 'F'))
	{
		if (*str >= 'a' && *str <= 'f')
			nb = *str - 'a' + 10;
		else if (*str >= 'A' && *str <= 'F')
			nb = *str - 'A' + 10;
		else
			nb = *str - '0';
		if (nb >= (unsigned int)base)
			return (0);
		ret = ret * base + nb;
		str++;
	}
	return (ret);
}

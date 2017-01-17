/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 22:13:18 by auverneu          #+#    #+#             */
/*   Updated: 2015/12/12 22:55:57 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*intmin(void)
{
	char	*strcpy;

	strcpy = NULL;
	strcpy = ft_strnew(11);
	strcpy = ft_strcpy(strcpy, "-2147483648");
	return (strcpy);
}

char		*ft_itoa(int n)
{
	int		i;
	char	*str;

	i = ft_intlen(n) - 1;
	if (n == -2147483648)
		return (intmin());
	str = ft_strnew(ft_intlen(n));
	if (str)
	{
		if (n == 0)
			str[0] = '0';
		if (n < 0)
		{
			str[0] = '-';
			n = -n;
		}
		while (n > 0)
		{
			str[i] = (n % 10) + 48;
			n = n / 10;
			i--;
		}
	}
	return (str);
}

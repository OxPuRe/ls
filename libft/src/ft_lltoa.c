/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 22:13:18 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/02 02:33:11 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_lltoa(long long n)
{
	int		i;
	char	*str;

	i = ft_llonglen(n);
	if (n == LLONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	str = ft_strnew(i);
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
			str[i - 1] = (n % 10) + 48;
			n = n / 10;
			i--;
		}
	}
	return (str);
}

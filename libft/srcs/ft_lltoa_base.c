/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 17:27:17 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/12 21:32:40 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void		val_low_z(int base, char *str, long long *value)
{
	if (value < 0)
	{
		if (base == 10)
			str[0] = '-';
		*value = -(*value);
	}
}

char			*ft_lltoa_base(long long value, int base)
{
	int			len;
	char		*str;
	char		*val;

	val = "0123456789abcdef";
	len = ft_llonglen_base(value, base);
	if (value == LONG_MIN && base == 10)
		return (ft_strdup("-9223372036854775808"));
	if (value == 0)
		return (ft_strdup("0"));
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	str[--len] = '\0';
	val_low_z(base, str, &value);
	while (value >= base)
	{
		str[len] = val[(value % base)];
		value = value / base;
		len--;
	}
	str[len] = val[(value % base)];
	if (str[0] == '-')
		str[--len] = '-';
	return (str);
}

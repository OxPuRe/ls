/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 17:27:17 by auverneu          #+#    #+#             */
/*   Updated: 2016/10/30 18:12:48 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void		ft_tostr(uintmax_t n, char *str, int base)
{
	*str = FT_XDIGIT[n % base];
	if (n / base != 0)
		ft_tostr(n / base, str - 1, base);
}

char			*ft_ulltoa_base(uintmax_t n, int base)
{
	char		*ret;
	size_t		len;

	len = ft_ilen_base(n, base);
	if (len == 0)
		return (NULL);
	ret = (char*)malloc(len + 1);
	if (ret == NULL)
		return (NULL);
	ft_tostr(n, ret + (len - 1), base);
	*(ret + len) = 0;
	return (ret);
}

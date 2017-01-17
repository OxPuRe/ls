/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctomb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 22:59:01 by auverneu          #+#    #+#             */
/*   Updated: 2016/08/24 01:44:41 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_wctomb(char *s, wchar_t w)
{
	int		i;
	int		len;

	i = 1;
	len = (int)ft_wclen(w);
	while (i < len)
	{
		s[len - i] = (char)((w & 63) | (UCHAR)FT_MASK_B);
		w >>= 6;
		i++;
	}
	s[0] = (char)(w | (UCHAR)FT_WC_MASK[len - 1]);
	return (len);
}

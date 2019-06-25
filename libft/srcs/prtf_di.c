/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prtf_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 21:15:22 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/07 23:59:41 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	prtf_di(t_file *prtf)
{
	if (prtf->flag[7] == 1)
		prtf->i = ft_lltoa((va_arg(prtf->ap, LLONG)));
	else if (prtf->flag[8] == 1)
		prtf->i = ft_lltoa((va_arg(prtf->ap, long)));
	else if (prtf->flag[5] == 1)
		prtf->i = ft_lltoa(((signed char)va_arg(prtf->ap, int)));
	else if (prtf->flag[6] == 1)
		prtf->i = ft_lltoa(((short)va_arg(prtf->ap, int)));
	else if (prtf->flag[9] == 1)
		prtf->i = ft_lltoa((va_arg(prtf->ap, intmax_t)));
	else if (prtf->flag[10] == 1)
		prtf->i = ft_lltoa((va_arg(prtf->ap, size_t)));
	else
		prtf->i = ft_lltoa((va_arg(prtf->ap, int)));
}

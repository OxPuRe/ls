/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prtf_cs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 19:47:37 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/02 06:52:06 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void			prtf_c(t_file *prtf)
{
	prtf->flag[4] = 0;
	if (prtf->flag[8] == 0)
	{
		prtf->i = ft_strnew(1);
		*(prtf->i) = (unsigned char)va_arg(prtf->ap, int);
	}
	if (*prtf->i == '\0' && prtf->flag[14] != 0)
		prtf->flag[14] -= 1;
}

void			prtf_s(t_file *prtf)
{
	char	*tmp;

	prtf->flag[4] = 0;
	if (prtf->flag[8] == 0)
	{
		if ((tmp = (char *)va_arg(prtf->ap, const char *)))
			tmp = ft_strdup(tmp);
		else
			tmp = ft_strdup("(null)");
		if (prtf->flag[12] != 0 && prtf->flag[11] >= 0)
			prtf->i = ft_strsub(tmp, 0, prtf->flag[11]);
		else
			prtf->i = ft_strdup(tmp);
		if (prtf->i[0] == '\0')
		{
			prtf->flag[11] = 0;
			prtf->flag[12] = 0;
		}
		if (prtf->flag[14] != 0)
			prtf->flag[11] = 0;
		free((void *)tmp);
	}
}

void			prtf_p(t_file *prtf)
{
	prtf->i = ft_ulltoa_base((long long)va_arg(prtf->ap, void *), 16);
	prtf->flag[0] = 1;
	prtf->flag[3] = 0;
}

void			prtf_percent(t_file *prtf)
{
	prtf->flag[12] = 0;
	prtf->flag[11] = 0;
	prtf->flag[4] = 0;
	prtf->i = ft_strdup("%");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prtf_csup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 01:52:27 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/12 20:07:30 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	prtf_c_up(t_file *prtf)
{
	int		i;
	char	s[5];
	wchar_t	w;

	ft_bzero(s, 5);
	if ((w = va_arg(prtf->ap, wchar_t)))
	{
		if ((i = ft_wctomb(s, w)) > 0)
			prtf->i = ft_strdup(s);
	}
	else
		prtf->i = ft_strdup("\0");
}

void	prtf_s_up(t_file *prtf, size_t k)
{
	int		i;
	size_t	j;
	wchar_t	*w;
	char	s[5];

	w = va_arg(prtf->ap, wchar_t*);
	if (w == NULL)
		prtf->i = ft_strdup("(null)");
	else if ((j = ft_wcstrlen(w)) > 0)
	{
		if ((prtf->i = ft_strnew(j)))
			while (*w)
			{
				ft_bzero(s, 5);
				if ((i = ft_wctomb(s, *w)) > 0)
				{
					ft_memmove(&prtf->i[k], s, i);
					k += i;
				}
				w++;
			}
	}
	else
		prtf->i = ft_strnew(0);
}

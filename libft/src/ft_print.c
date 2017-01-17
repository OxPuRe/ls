/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 18:14:32 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/02 08:29:36 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void			ft_print(t_file *prtf)
{
	int		i;

	i = (int)ft_strlen(prtf->i);
	prtf->mem = prtf->i;
	if ((ft_strchr("dDioOuUxX", *prtf->form) != NULL))
	{
		if (prtf->flag[12] == 1 && prtf->flag[11] == 0 &&
			(ft_strcmp(prtf->i, "0") == 0))
		{
			prtf->i = "\0";
			i = 0;
		}
		if (*(prtf->i) == '-')
		{
			prtf->flag[15] = 1;
			prtf->flag[3] = 0;
			(prtf->i)++;
			i--;
		}
	}
	display_o(prtf, &i);
	display_t(prtf, i, 0);
	free(prtf->mem);
}

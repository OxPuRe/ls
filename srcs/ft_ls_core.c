/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 11:09:47 by auverneu          #+#    #+#             */
/*   Updated: 2019/06/26 07:03:12 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_ls_core(t_ls *ls)
{
	t_ls		*lsr;
	int			i;

	i = 0;
	while (i < ls->nbe)
	{
		if (ft_strcmp(ls->arg[i].name, ".") && ls->nbe > 1)
			ft_printf("%s:\n", ls->arg[i].name);
		lsr = ft_ls_info(ls, i);
		if (lsr != NULL && ls->flag & LS_F_RECURSIVE)
		{
			ft_ls_core(lsr);
		}
		i++;
		if (i < ls->nbe)
			ft_printf("\n");
	}
	free(ls);
	return (0);
}

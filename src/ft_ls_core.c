/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 11:09:47 by auverneu          #+#    #+#             */
/*   Updated: 2019/04/18 15:45:39 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_ls_core(t_structls *ls)
{
	t_structls	lsr;
	int		i;

	i = 0;
	lsr.ex = ls->ex;
	lsr.flag = ls->flag;
	lsr.nbe = 0;
	while (ls->nbe)
	{
		if (strcmp(ls->elem[i], ".") && ls->nbe > 1)
	 		ft_printf("%s:\n", ls->elem[i]);
		lsr.elem = ft_info_ls(ft_strjoin(ls->elem[i], "/"), &lsr);
		if ((ls->flag & F_RR) && lsr.elem != NULL)
		{
			ft_ls_core(&lsr);
		}
		if (ls->elem[i + 1])
			printf("\n");
		ls->nbe--;
		i++;
	}
	return (0);
}
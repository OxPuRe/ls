/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 11:09:47 by auverneu          #+#    #+#             */
/*   Updated: 2019/04/25 17:53:17 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_ls_core(t_stls *ls, t_infols *info)
{
	t_infols	*info_r;
	int			i;

	i = 0;
	while (ls->nbe)
	{
		if (ft_strcmp(info[i].name, ".") && ls->nbe > 1)
			ft_printf("%s:\n", info[i].name);
		info_r = ft_ls_info(ft_strjoin(info[i].name, "/"), ls);
		if ((ls->flag & F_RR) && info_r != NULL)
		{
			ft_ls_core(ls, info_r);
		}
		ls->nbe--;
		if (ls->nbe)
			printf("\n");
		i++;
	}
	return (0);
}

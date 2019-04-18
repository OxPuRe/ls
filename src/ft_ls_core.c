/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 11:09:47 by auverneu          #+#    #+#             */
/*   Updated: 2019/04/18 11:21:54 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_ls_core(t_structls *ls)
{
	char	**dir;
	int		i;

	i = 0;
	while (ls->nb)
	{
		if (strcmp(ls->paths[i], ".") && ls->nb > 1)
	 		ft_printf("%s:\n", ls->paths[i]);
		dir = ft_info_ls(ls, ft_strjoin(ls->paths[i], "/"));
		if ((ls->flags & F_RR) && *dir != NULL)
		{
			test(ls, ls->paths);
		}
		if (ls->paths[i + 1])
			printf("\n");
		ls->nb--;
		i++;
	}
	return (0);
}
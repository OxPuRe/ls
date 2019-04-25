/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:51:58 by auverneu          #+#    #+#             */
/*   Updated: 2019/04/25 16:48:00 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_infols		*ft_ls_print(t_infols *info, t_stls *ls, t_var *v)
{
	int			i;
	t_list		*list;
	t_list		*mem;
	t_infols	*info_r;

	i = 0;
	list = NULL;
	mem = list;
	info_r = NULL;
	while (i < v->tmp)
	{
		printf("[%s]\n", info[i].name);
		if ((ls->flag & F_RR) && info[i].type == 'd')
		{
			if (mem == NULL)
			{
				mem = ft_lstnew(info[i].name, ft_strlen(info[i].name));
				list = mem;
			}
			else
			{
				list->next = ft_lstnew(info[i].name, ft_strlen(info[i].name));
				list = list->next;
			}
		}
		i++;
	}
	if (mem)
	{
		ft_ls_convert(mem, info_r, ls->nbe);
		return (info_r);
	}
	else
		return (NULL);
}

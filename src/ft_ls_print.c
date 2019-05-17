/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:51:58 by auverneu          #+#    #+#             */
/*   Updated: 2019/05/17 19:43:05 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				ft_ls_rec(t_list *mem, t_stls *lsr, int nbe, t_stls *ls)
{
	int				i;

	i = 0;
	lsr->ex = ls->ex;
	lsr->flag = ls->flag;
	lsr->nbe = nbe;
	while (i < nbe)
	{
		lsr->arg[i].name = mem->content;
		mem = mem->next;
		i++;
	}
}

t_stls			*ft_ls_print(t_infols *info, t_stls *ls, t_var *v)
{
	int			i;
	t_list		*list;
	t_list		*mem;
	t_stls		*lsr;

	i = 0;
	list = NULL;
	mem = NULL;
	lsr = NULL;
	while (i < v->tmp)
	{
		printf("%s\n", info[i].name);
		if ((ls->flag & F_RR) && info[i].type == 'd')
		{
			ft_ls_list(mem, list, info[i].name);
		}
		i++;
	}
	if (mem)
	{
		lsr = malloc(sizeof(t_stls) * i);
		ft_ls_rec(mem, lsr, i, ls);
		return (lsr);
	}
	else
		return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:51:58 by auverneu          #+#    #+#             */
/*   Updated: 2019/05/29 17:44:25 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_stls				*ft_ls_rec(t_list *mem, int nbe, t_stls *ls)
{
	int				i;
	t_stls			*lsr;

	i = 0;
	lsr = malloc(sizeof(t_stls));
	lsr->ex = ls->ex;
	lsr->flag = ls->flag;
	lsr->nbe = nbe;
	lsr->arg = malloc(sizeof(t_arg) * nbe);
	while (i < nbe)
	{
		lsr->arg[i].name = mem->content;
		mem = mem->next;
		i++;
	}
	return (lsr);
}

t_stls			*ft_ls_print(t_infols *info, t_stls *ls, t_var *v, int j)
{
	int			i;
	int			nbe;
	t_list		*list;
	t_list		*mem;

	i = 0;
	list = NULL;
	mem = NULL;
	nbe = 0;
	while (i < v->tmp)
	{
		printf("%s\n", info[i].name);
		if ((ls->flag & F_RR) != 0 && info[i].type == 'd')
		{
			if (!(info[i].name[0] == '.' && (info[i].name[1] == 0 ||
					(info[i].name[1] == '.' && info[i].name[2] == 0))))
			{
				ft_ls_list(&mem, &list, ft_strjoin(ls->arg[j].name, info[i].name));
				nbe++;
			}
		}
		i++;
	}
	if (mem)
		return (ft_ls_rec(mem, nbe, ls));
	else
		return (NULL);
}

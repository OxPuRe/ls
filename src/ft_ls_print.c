/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:51:58 by auverneu          #+#    #+#             */
/*   Updated: 2019/06/09 23:40:13 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls				*ft_ls_rec(t_list *mem, int nbe, t_ls *ls)
{
	int				i;
	t_ls			*lsr;

	i = 0;
	lsr = malloc(sizeof(t_ls));
	lsr->ex = ls->ex;
	lsr->flag = ls->flag;
	lsr->nbe = nbe;
	lsr->arg = malloc(sizeof(t_infols) * nbe);
	while (i < nbe)
	{
		lsr->arg[i].name = mem->content;
		mem = mem->next;
		i++;
	}
	return (lsr);
}

t_ls			*ft_ls_print(t_infols *info, t_ls *ls, t_var *v, int j)
{
	int			i;
	int			nbe;
	t_list		*list;
	t_list		*mem;

	i = 0;
	list = NULL;
	mem = NULL;
	nbe = 0;
	if ((ls->flag & LS_F_LONG))
		printf("total %lld\n", v->blk);
	while (i < v->s.s.tmp)
	{
		if (!(info[i].name[0] == '.' && (info[i].name[1] == 0 ||
				(info[i].name[1] == '.' && info[i].name[2] == 0))))
		{
			if ((ls->flag & LS_F_RECURSIVE) != 0 && info[i].type == 'd')
			{
				ft_ls_list(&mem, &list, ft_strjoin(ls->arg[j].name,
							info[i].name));
				nbe++;
			}
		}
		if ((ls->flag & LS_F_LONG))
			printf("%c%-10s %*lu %-*s %-*s %*lld [date] %s\n", info[i].type,
					info[i].rights, v->s.s.s_lk, info[i].link, v->s.s.s_own + 1,
					info[i].owner, v->s.s.s_grp + 1, info[i].group, v->s.s.s_sz,
					info[i].size, info[i].name);
		else
			printf("%s\n", info[i].name);
		free(info[i].name);
		i++;
	}
	free(info);
	if (mem)
		return (ft_ls_rec(mem, nbe, ls));
	else
		return (NULL);
}

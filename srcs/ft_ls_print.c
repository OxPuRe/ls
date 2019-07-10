/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:51:58 by auverneu          #+#    #+#             */
/*   Updated: 2019/07/10 03:51:11 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls			*ft_ls_rec(t_list *mem, int nbe, t_ls *ls)
{
	int			i;
	t_ls		*lsr;
	t_var		v;
	t_list		*first;

	v.s.init = 0;
	i = 0;
	lsr = malloc(sizeof(t_ls));
	lsr->ex = ls->ex;
	lsr->flag = ls->flag;
	lsr->nbe = nbe;
	lsr->arg = malloc(sizeof(t_infols) * nbe);
	first = mem;
	while (i < nbe)
	{
		lsr->arg[i].name = mem->content;
		lsr->arg[i].type = 'd';
		mem = mem->next;
		i++;
	}
	ft_lstdel(&first, ft_ls_del);
	return (lsr);
}

static void		ls_get_time(t_infols *info)
{
	time_t		tm;
	char		*strt_year;
	char		*end_tme;
	char		*str_tme;

	str_tme = ctime(&(info->tme_spec.tv_sec));
	ft_strncpy(info->date, str_tme + 4, 12);
	info->date[12] = 0;
	time(&tm);
	if ((info->tme_spec.tv_sec < (tm - LS_SW_TIME)) ||
		(info->tme_spec.tv_sec > (tm + LS_SW_TIME)))
	{
		end_tme = ft_strchr(str_tme, '\n');
		strt_year = end_tme - 1;
		while (ft_isdigit(*strt_year))
			strt_year--;
		strt_year++;
		ft_strncpy(info->date + 8, strt_year, end_tme - strt_year);
		info->date[11] = 0;
	}
}

static void		display(t_infols *info, t_ls *ls, t_var *v, int i)
{
	if ((ls->flag & LS_F_LONG))
	{
		ls_get_time(&info[i]);
		if (info[i].type == 'c' || info[i].type == 'b')
			ft_printf("%c%-10s %*lu %-*s %-*s %*d, %*d %s %s\n",
				info[i].type, info[i].rights, v->s.s.s_lk, info[i].link,
				v->s.s.s_own + 1, info[i].owner, v->s.s.s_grp + 1,
				info[i].group, v->s.s.s_maj, info[i].major, v->s.s.s_min,
				info[i].minor, info[i].date, info[i].name);
		else
			ft_printf("%c%-10s %*lu %-*s %-*s %*lld %s %s\n", info[i].type,
				info[i].rights, v->s.s.s_lk, info[i].link, v->s.s.s_own + 1,
				info[i].owner, v->s.s.s_grp + 1, info[i].group, v->s.s.s_sz,
				info[i].size, info[i].date, info[i].name);
	}
	else
		ft_printf("%s\n", info[i].name);
}

static t_list	*loop(t_infols *info, t_ls *ls, t_var *v, int j)
{
	int			i;
	t_list		*list;
	t_list		*mem;

	i = 0;
	list = NULL;
	mem = NULL;
	while (i < v->s.s.tmp)
	{
		display(info, ls, v, i);
		if (!(info[i].name[0] == '.' && (info[i].name[1] == 0 ||
				(info[i].name[1] == '.' && info[i].name[2] == 0))))
			if ((ls->flag & LS_F_RECURSIVE) != 0 && info[i].type == 'd')
			{
				if (!(info[i].name = ft_strxjoin("001", ls->arg[j].name, "/",
					info[i].name)))
					ls_exit(LS_E_STD_EXIT, NULL, ls);
				ft_ls_list(&mem, &list, info[i].name);
				v->blk++;
			}
		free(info[i].name);
		i++;
	}
	return (mem);
}

t_ls			*ft_ls_print(t_infols *info, t_ls *ls, t_var *v, int j)
{
	t_list		*mem;

	mem = NULL;
	if (v->s.s.s_min < v->s.s.s_maj)
		v->s.s.s_min = v->s.s.s_maj;
	else
		v->s.s.s_maj = v->s.s.s_min;
	if (v->s.s.s_sz > (v->s.s.s_min + v->s.s.s_maj + 2))
		v->s.s.s_maj = v->s.s.s_sz - v->s.s.s_min - 2;
	else
		v->s.s.s_sz = v->s.s.s_min + v->s.s.s_maj + 2;
	if ((ls->flag & LS_F_LONG) && ls->arg->type == 'd')
		ft_printf("total %lld\n", v->blk);
	v->blk = 0;
	mem = loop(info, ls, v, j);
	free(info);
	free(ls->arg[j].name);
	if (mem)
		return (ft_ls_rec(mem, (int)v->blk, ls));
	else
		return (NULL);
}

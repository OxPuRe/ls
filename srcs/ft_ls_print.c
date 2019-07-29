/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:51:58 by auverneu          #+#    #+#             */
/*   Updated: 2019/07/29 02:58:16 by auverneu         ###   ########.fr       */
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
	lsr->aff_dir = ls->aff_dir;
	lsr->arg = malloc(sizeof(t_infols) * nbe);
	first = mem;
	while (i < nbe)
	{
		lsr->arg[i].name = ft_strdup(mem->content);
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
	char		*str_tme;
	char		**d;
	int			i;

	i = 0;
	str_tme = ctime(&(info->tme_spec.tv_sec));
	d = ft_strsplit(str_tme, 32);
	time(&tm);
	d[3][5] = 0;
	d[4][ft_strlen(d[4]) - 1] = 0;
	if ((info->tme_spec.tv_sec < (tm - LS_SW_TIME)) ||
		(info->tme_spec.tv_sec > (tm + LS_SW_TIME)))
		ft_printf("%s %2s  %s ", d[1], d[2], d[4]);
	else
		ft_printf("%s %2s %5s ", d[1], d[2], d[3]);
	while (i < 5)
	{
		free(d[i]);
		i++;
	}
	free(d);
}

static void		display(t_infols *info, t_ls *ls, t_var *v, int i)
{
	if ((ls->flag & LS_F_LONG))
	{
		if (info[i].type == 'c' || info[i].type == 'b')
			ft_printf("%c%-10s %*lu %-*s  %-*s %*d, %*d ",
				info[i].type, info[i].rights, v->s.s.s_lk, info[i].link,
				v->s.s.s_own, info[i].owner->pw_name, v->s.s.s_grp,
				info[i].group->gr_name, v->s.s.s_maj, info[i].major,
				v->s.s.s_min, info[i].minor);
		else
			ft_printf("%c%-10s %*lu %-*s  %-*s  %*lld ", info[i].type,
				info[i].rights, v->s.s.s_lk, info[i].link, v->s.s.s_own,
				info[i].owner->pw_name, v->s.s.s_grp, info[i].group->gr_name,
				v->s.s.s_sz, info[i].size);
		ls_get_time(&info[i]);
	}
	ft_printf("%s\n", info[i].name);
	ls->aff_dir = 1;
}

static t_list	*loop(t_infols *info, t_ls *ls, t_var *v, int j)
{
	int			i;
	t_list		*list;
	t_list		*mem;
	char		*tmp;

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
				tmp = info[i].name;
				if (!(info[i].name = ft_pathjoin(ls->arg[j].name, tmp, 1, "/")))
					ls_exit(LS_E_STD_EXIT, NULL, ls);
				free(tmp);
				ft_ls_list(&mem, &list, info[i].name);
				v->blk++;
			}
		free(info[i++].name);
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
	if (v->s.s.s_sz > (v->s.s.s_min + v->s.s.s_maj + 2) &&
		(v->s.s.s_min + v->s.s.s_maj) >= 2)
		v->s.s.s_maj = v->s.s.s_sz - v->s.s.s_min - 2;
	else if (v->s.s.s_sz < (v->s.s.s_min + v->s.s.s_maj + 2) &&
		(v->s.s.s_min + v->s.s.s_maj) >= 2)
		v->s.s.s_sz = v->s.s.s_min + v->s.s.s_maj + 2;
	if ((ls->flag & LS_F_LONG) && ls->arg->type == 'd' && v->s.s.tmp)
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

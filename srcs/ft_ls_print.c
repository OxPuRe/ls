/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:51:58 by auverneu          #+#    #+#             */
/*   Updated: 2019/08/17 03:03:27 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ls_rec(t_list *mem, t_ls *ls, t_ls *lsr)
{
	size_t		i;
	t_list		*first;

	i = 0;
	lsr->ex = ls->ex;
	lsr->flag = ls->flag;
	lsr->aff_dir = ls->aff_dir;
	lsr->path = (char **)ls_malloc(sizeof(char *) * lsr->nbe, ls);
	first = mem;
	while (i < lsr->nbe)
	{
		if (!(lsr->path[i] = ft_pathjoin(*ls->path,
			((t_info *)mem->content)->name, 1, "/")))
			ls_exit(LS_E_STD_EXIT, NULL, ls);
		mem = mem->next;
		i++;
	}
	ft_lstdel(&first, ls_del);
}

char			*ls_print_link(char *name, int mode, t_ls *ls)
{
	size_t		size;
	char		*str;
	char		*tmp;
	int			ret;

	size = LS_SL_BUFF;
	while (42)
	{
		str = (char *)ls_malloc(sizeof(char) * size + 1, ls);
		if (!(tmp = ft_pathjoin(*ls->path, name, 1, "/")))
			ls_exit(LS_E_STD_EXIT, NULL, ls);
		if ((ret = readlink(tmp, str, size)) == -1)
			ls_exit(LS_E_STD_EXIT, tmp, ls);
		free(tmp);
		if (ret != (int)size)
			break ;
		free(str);
		size += LS_SL_BUFF;
	}
	str[ret] = '\0';
	if (mode)
		return (str);
	ft_printf("%s -> %s\n", name, str);
	free(str);
	return (NULL);
}

static void		ls_print_time(t_info *info)
{
	time_t		tm;
	char		*str_tme;
	char		**d;
	int			i;

	i = 0;
	str_tme = ctime(&(info->timespec.tv_sec));
	d = ft_strsplit(str_tme, 32);
	time(&tm);
	d[3][5] = 0;
	d[4][ft_strlen(d[4]) - 1] = 0;
	if ((info->timespec.tv_sec < (tm - LS_SW_TIME)) ||
		(info->timespec.tv_sec > (tm + LS_SW_TIME)))
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

static void		ls_print(t_info *info, t_print *print, t_ls *ls)
{
	if ((ls->flag & LS_F_LONG))
	{
		if (info->mode[0] == 'c' || info->mode[0] == 'b')
			ft_printf("%-11s %*lu %-*s  %-*s %*d, %*d ", info->mode,
				print->s.s.lk, info->stat.st_nlink, print->s.s.own, info->owner,
				print->s.s.grp, info->group, print->s.s.maj,
				major(info->stat.st_rdev), print->s.s.min,
				minor(info->stat.st_rdev));
		else
			ft_printf("%-11s %*lu %-*s  %-*s  %*lld ", info->mode,
			print->s.s.lk, info->stat.st_nlink, print->s.s.own, info->owner,
			print->s.s.grp, info->group, print->s.s.sz, info->size);
		ls_print_time(info);
	}
	if ((ls->flag & LS_F_LONG) && info->mode[0] == 'l')
		ls_print_link(info->name, 0, ls);
	else
		ft_printf("%s\n", info->name);
	ls->aff_dir = 1;
}

void			ls_display(t_info *info, t_print *print, t_ls *ls, t_ls *lsr)
{
	t_list		*elem;
	t_list		*first;
	size_t		i;

	i = 0;
	elem = NULL;
	first = elem;
	while (i < print->nbe)
	{
		ls_print(&info[i], print, ls);
		if (!(info[i].name[0] == '.' && (info[i].name[1] == 0 ||
				(info[i].name[1] == '.' && info[i].name[2] == 0))) &&
				(ls->flag & LS_F_RECURSIVE) != 0 && info[i].mode[0] == 'd')
		{
			ls_list(&first, &elem, &info[i]);
			lsr->nbe++;
		}
		free(info[i].owner);
		free(info[i].group);
		i++;
	}
	free(info);
	if (lsr->nbe)
		ls_rec(first, ls, lsr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 11:09:47 by auverneu          #+#    #+#             */
/*   Updated: 2019/08/19 23:26:29 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ls_convert(t_list *mem, t_info *info, t_print *print, t_ls *ls)
{
	size_t		i;
	t_list		*first;

	i = 0;
	first = mem;
	print->block = 0;
	print->s.init = 0;
	while (i < print->nbe)
	{
		ft_memcpy(&info[i], mem->content, sizeof(t_info));
		ls_info(&info[i], print, ls);
		print->block += info[i].stat.st_blocks;
		mem = mem->next;
		i++;
	}
	ft_lstdel(&first, ls_del);
	print->s.s.maj = ft_max(print->s.s.min, print->s.s.maj);
	print->s.s.min = ft_max(print->s.s.min, print->s.s.maj);
	if (print->s.s.sz > print->s.s.maj * 2 + 2 && print->s.s.maj * 2 >= 2)
		print->s.s.maj = print->s.s.sz - print->s.s.maj - 2;
	else if (print->s.s.sz < print->s.s.min * 2 + 2 && print->s.s.min * 2 >= 2)
		print->s.s.sz = print->s.s.min * 2 + 2;
	if ((ls->flag & LS_F_NOSORT) == 0)
		ls_sort(info, ls->flag, print->nbe);
}

static void		ls_new_link(t_list *elem[2], t_var *v, t_print *print, t_ls *ls)
{
	char		*tmp;

	tmp = ft_pathjoin(*ls->path, v->rd->d_name, 1, "/");
	if (!lstat(tmp, &v->elem.stat))
	{
		ft_strcpy(v->elem.name, v->rd->d_name);
		ls_list(&elem[0], &elem[1], &v->elem);
		print->nbe += 1;
	}
	free(tmp);
}

static void		ls_read(t_info **info, t_print *print, t_ls *ls)
{
	t_list		*elem[2];
	t_var		v;

	elem[0] = NULL;
	elem[1] = NULL;
	print->nbe = 0;
	if (!(v.op = opendir(*ls->path)))
		ls_exit(LS_E_STD, *ls->path, ls);
	else
	{
		while ((v.rd = readdir(v.op)) != NULL)
			if (v.rd->d_name[0] != '.' || (!(v.rd->d_name[0] == '.' &&
		(v.rd->d_name[1] == 0 || (v.rd->d_name[1] == '.' &&
		v.rd->d_name[2] == 0))) && ls->flag & LS_F_AALL) || ls->flag & LS_F_ALL)
			{
				ls_new_link(elem, &v, print, ls);
			}
		closedir(v.op);
	}
	if (print->nbe)
	{
		*info = (t_info*)ls_malloc(sizeof(t_info) * print->nbe, ls);
		ls_convert(elem[0], *info, print, ls);
	}
}

int				ls_core(t_ls *ls)
{
	t_ls		lsr;
	size_t		i;
	t_info		*info;
	t_print		print;
	char		**mem;

	i = 0;
	info = NULL;
	mem = ls->path;
	while (i++ < ls->nbe)
	{
		lsr.nbe = 0;
		(ls->nbe > 1 || ls->aff_dir) ? ft_printf("%s:\n", *ls->path) : 0;
		ls_read(&info, &print, ls);
		print.nbe && ls->flag & LS_F_LONG ? ft_printf("total %lld\n",
		print.block) : 0;
		print.nbe ? ls_display(info, &print, ls, &lsr) : 0;
		free(*ls->path);
		lsr.nbe ? ft_printf("\n") : 0;
		lsr.nbe ? ls_core(&lsr) : 0;
		ls->path++;
		i < ls->nbe ? ft_printf("\n") : 0;
	}
	free(mem);
	return (0);
}

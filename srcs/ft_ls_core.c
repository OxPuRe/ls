/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 11:09:47 by auverneu          #+#    #+#             */
/*   Updated: 2019/08/08 16:07:08 by auverneu         ###   ########.fr       */
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
	print->s.s.min = ft_max(print->s.s.min, print->s.s.maj);
	print->s.s.maj = ft_max(print->s.s.min, print->s.s.maj);
	if (print->s.s.sz > print->s.s.min * 2 + 2 && print->s.s.min * 2 >= 2)
		print->s.s.maj = print->s.s.sz - print->s.s.min - 2;
	else if (print->s.s.sz < print->s.s.min * 2 + 2 && print->s.s.min * 2 >= 2)
		print->s.s.sz = print->s.s.min * 2 + 2;
	if ((ls->flag & LS_F_NOSORT) == 0)
		ls_sort(info, ls->flag, print->nbe);
}

static void		ls_read(t_info **info, t_print *print, t_ls *ls)
{
	t_list		*elem;
	t_list		*first;
	char		*tmp;
	t_var		v;

	elem = NULL;
	first = elem;
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
				tmp = ft_pathjoin(*ls->path, v.rd->d_name, 1, "/");
				if (!lstat(tmp, &v.elem.stat))
				{
					ft_strcpy(v.elem.name, v.rd->d_name);
					ls_list(&first, &elem, &v.elem);
					print->nbe += 1;
				}
				free(tmp);
			}
		closedir(v.op);
	}
	if (print->nbe)
	{
		*info = (t_info*)ls_malloc(sizeof(t_info) * print->nbe, ls);
		ls_convert(first, *info, print, ls);
	}
}

int				ls_core(t_ls *ls)
{
	t_ls		lsr;
	size_t		i;
	t_info		*info;
	t_print		print;

	i = 0;
	info = NULL;
	while (i < ls->nbe)
	{
		lsr.nbe = 0;
		if (ls->nbe > 1 || ls->aff_dir)
			ft_printf("%s:\n", *ls->path);
		ls_read(&info, &print, ls);
		if (print.nbe)
		{
			if ((ls->flag & LS_F_LONG))
				ft_printf("total %lld\n", print.block);
			ls_display(info, &print, ls, &lsr);
		}
		if (lsr.nbe)
		{
			ft_printf("\n");
			ls_core(&lsr);
		}
		ls->path++;
		i++;
		if (i < ls->nbe)
			ft_printf("\n");
	}
	return (0);
}
